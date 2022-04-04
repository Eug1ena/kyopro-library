template<class T = int>
struct SCC{
    Graph<T> graph, rev;

    int id;
    vector<int> id_inv;
    vector<bool> used;
    
    vector<int> comp;
    vector<vector<int>> groups;
    Graph<T> dag;

    void dfs(int at){
        used[at] = true;
        for(int to: graph[at]){
            if(used[to]) continue;
            dfs(to);
        }
        id_inv[id] = at;
        id++;
    }
    
    int group_id;
    
    void dfs2(int at){
        comp[at] = group_id;
        groups.back().push_back(at);
        used[at] = true;
        for(int to: rev[at]){
            if(used[to]) continue;
            dfs2(to);
        }
    }

    SCC(Graph<T> g): graph(g){
        int n = int(graph.size());
        
        rev = Graph<T>(n);
        rep(i, n){
            for(auto j: graph[i]){
                rev.add_directed_edge(j, i);
            }
        }
        
        id_inv.assign(n, -1);
        used.assign(n, false);
        id = 0;
        rep(i, n){
            if(used[i]) continue;
            dfs(i);
        }
        
        used.assign(n, false);
        comp.assign(n, -1);
        group_id = 0;
        repr(i, n){
            int v = id_inv[i];
            if(used[v]) continue;
            groups.push_back({});
            dfs2(v);
            group_id++;
        }
        
        dag = Graph<T>(group_id);
        rep(i, n){
            for(auto e: graph[i]){
                if(comp[i] != comp[e.to]){
                    dag.add_directed_edge(comp[i], comp[e.to], e.cost);
                }
            }
        }
    }
};
