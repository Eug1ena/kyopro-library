template<class T>
struct GraphCollection{
    struct edge{
        int to;
        T cost;
    };
    
    int sz;
    vector<vector<edge>> graph;
    T INF;
    
    GraphCollection(int n): sz(n), graph(n) {
        INF = numeric_limits<T>::max();
    }
    
    void replace_INF(vector<T> &v){
        for(auto &x: v){
            if(x == INF) x = -1;
        }
    }
    
    void add_edge(int from, int to, T cost = -1){
        graph[from].push_back({to, cost});
    }
    
    vector<T> BFS(int s){
        vector<T> dist(sz, INF);
        dist[s] = 0;
        queue<int> que;
        que.push(s);
        
        while(!que.empty()){
            int at = que.front();
            que.pop();
            for(edge e: graph[at]){
                if(dist[e.to] == INF){
                    dist[e.to] = dist[at] + 1;
                    que.push(e.to);
                }
            }
        }
        
        replace_INF(dist);
        return dist;
    }
    
    vector<T> BFS01(int s){
        vector<T> dist(sz, INF);
        dist[s] = 0;
        deque<pair<int, T>> que;
        que.push_back({s, 0});
        
        while(!que.empty()){
            auto top = que.front();
            que.pop_back();
            int at = top.first;
            T cost = top.second;
            if(dist[at] < cost) continue;
            
            for(edge e: graph[at]){
                if(cost + e.cost < dist[e.to]){
                    dist[e.to] = dist[at] + e.cost;
                    if(e.cost == 0){
                        que.push_front({e.to, dist[e.to]});
                    }else{
                        que.push_back({e.to, dist[e.to]});
                    }
                }
            }
        }
        
        replace_INF(dist);
        return dist;
    }
    
    vector<T> dijkstra(int s){
        vector<T> dist(sz, INF);
        dist[s] = 0;
        using P = pair<T, int>;
        priority_queue<P, vector<P>, greater<P>> que;
        que.push({0, s});
        
        while(!que.empty()){
            auto top = que.top();
            que.pop();
            int at = top.second;
            T cost = top.first;
            if(dist[at] < cost) continue;
            
            for(edge e: graph[at]){
                if(cost + e.cost < dist[e.to]){
                    dist[e.to] = dist[at] + e.cost;
                    que.push({dist[e.to], e.to});
                }
            }
        }
        
        replace_INF(dist);
        return dist;
    }
    
};
