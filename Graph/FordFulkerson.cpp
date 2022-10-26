template<class T>
struct FordFulkerson{
    const T INF;
    
    struct rev_edge{
        int to;
        T cap;
        int rev;
        bool is_rev;
    };

    int n;
    vector<vector<rev_edge>> g;
    vector<bool> used;
    
    FordFulkerson(int sz): n(sz), g(sz), used(sz), INF(numeric_limits<T>::max()) {}

    void add_edge(int from, int to, T cap){
        g[from].push_back({to, cap, int(g[to].size()), false});
        g[to].push_back({from, 0, int(g[from].size()) - 1, true});
    }

    T dfs(int v, int t, T flow){
        if(v == t) return flow;
        used[v] = true;
        for(auto &e: g[v]){
            if(!used[e.to] && e.cap > 0){
                T d = dfs(e.to, t, min(flow, e.cap));
                if(d > 0){
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    
    T max_flow(int s, int t){
        T flow = 0;
        while(true){
            used.assign(n, false);
            T f = dfs(s, t, INF);
            if(f == 0) return flow;
            flow += f;
        }
    }
    
    void output(){
        rep(i, n){
            for(auto e: g[i]){
                if(!e.is_rev){
                    T f = g[e.to][e.rev].cap;
                    cout << i << "->" << e.to << ": " << f << endl;
                }
            }
        }
    }
};
