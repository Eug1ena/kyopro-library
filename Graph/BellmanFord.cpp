template<class T>
pair<vector<T>, bool> BellmanFord(const Graph<T> &g, int s){ // [dist], is_negative_loop
    int n = int(g.size());
    
    vector<T> d(n, g.INF);
    d[s] = 0;
    
    bool is_negative_loop = false;
    rep(c, n){
        rep(at, n) for(auto e: g[at]){
            int to = e.to;
            if(d[at] != g.INF && d[to] > d[at] + e.cost){
                d[to] = d[at] + e.cost;
                
                if(c == n - 1){
                    is_negative_loop = true;
                    d[to] = -g.INF;
                }
            }
        }
    }
    
    if(!is_negative_loop) return {d, false};
    
    // 負閉路込みでの最短経路
    queue<int> que;
    rep(i, n){
        if(d[i] <= -g.INF){
            que.push(i);
            d[i] = -g.INF;
        }
    }
    
    while(!que.empty()){
        int at = que.front();
        que.pop();
        for(int to: g[at]){
            if(d[to] != -g.INF){
                d[to] = -g.INF;
                que.push(to);
            }
        }
    }
    
    return {d, true};
}
