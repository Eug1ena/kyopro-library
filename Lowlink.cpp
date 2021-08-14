struct Lowlink{
    Graph<int> graph;

    vector<int> in, low;
    vector<bool> is_bridge, is_articulation;

    void dfs(int at, int back_id, int &num){
        in[at] = low[at] = num;
        num++;
        
        int cnt = 0;
        for(auto e: graph[at]){
            if(e.id == back_id) continue;
            
            int to = e.to;
            if(in[to] != -1){
                low[at] = min(low[at], in[to]);
                continue;
            }
            
            dfs(to, e.id, num);
            if(in[at] < low[to]){
                is_bridge[e.id] = true;
            }
            if(in[at] <= low[to]){
                is_articulation[at] = true;
            }
            low[at] = min(low[at], low[to]);
            
            cnt++;
        }
        if(back_id == -1){
            is_articulation[at] = (cnt >= 2);
        }
    }

    Lowlink(Graph<int> g): graph(g){
        int n = int(g.size());
        
        in.assign(n, -1);
        low.assign(n, -1);
        is_bridge.assign(g.edge_cnt, false);
        is_articulation.assign(n, false);
        
        rep(i, n){
            if(in[i] != -1) continue;
            int tmp = 0;
            dfs(i, -1, tmp);
        }
    }
};
