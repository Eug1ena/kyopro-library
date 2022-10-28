template<class flowT, class costT>
struct MinCostFlow{
    const costT INF;
    
    struct rev_edge{
        int to;
        flowT cap;
        costT cost;
        int rev;
        bool is_rev;
    };
    
    int n;
    vector<vector<rev_edge>> g;
    vector<costT> h; // potential
    vector<costT> dist;
    vector<int> prev_v, prev_e;
    
    MinCostFlow(int sz): n(sz), g(sz), h(sz), dist(sz), prev_v(sz), prev_e(sz), INF(numeric_limits<costT>::max()) {}
    
    void add_edge(int from, int to, flowT cap, costT cost){
        g[from].push_back({to, cap, cost, int(g[to].size()), false});
        g[to].push_back({from, 0, -cost, int(g[from].size()) - 1, true});
    }
    
    costT min_cost_flow(int s, int t, flowT flow){
        costT res = 0;
        h.assign(n, 0);
        while(flow > 0){
            using P = pair<costT, int>; // cost, at
            priority_queue<P, vector<P>, greater<P>> que;
            
            dist.assign(n, INF);
            dist[s] = 0;
            que.push({0, s});
            while(!que.empty()){
                P top = que.top();
                que.pop();
                costT cost = top.first;
                int at = top.second;
                if(dist[at] < cost) continue;
                
                rep(i, g[at].size()){
                    rev_edge e = g[at][i];
                    int to = e.to;
                    if(e.cap > 0 && dist[to] > dist[at] + (e.cost + h[at] - h[to])){
                        dist[to] = dist[at] + (e.cost + h[at] - h[to]);
                        prev_v[to] = at;
                        prev_e[to] = i;
                        que.push({dist[to], to});
                    }
                }
            }
            
            if(dist[t] == INF){
                return -1;
            }
            rep(i, n) h[i] += dist[i];
            
            flowT f = flow;
            for(int at = t; at != s; at = prev_v[at]){
                f = min(f, g[prev_v[at]][prev_e[at]].cap);
            }
            
            flow -= f;
            res += f * h[t];
            for(int at = t; at != s; at = prev_v[at]){
                rev_edge &e = g[prev_v[at]][prev_e[at]];
                e.cap -= f;
                g[at][e.rev].cap += f;
            }
        }
        
        return res;
    }
    
    void output(){
        rep(i, n) for(auto e: g[i]){
            if(!e.is_rev){
                flowT f = g[e.to][e.rev].cap;
                cout << i << "->" << e.to << ": " << f << endl;
            }
        }
    }
};
