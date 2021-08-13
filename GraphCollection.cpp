template<class T>
vector<T> BFS(Graph<T> graph, int s){
    int n = int(graph.size());
    T INF = (numeric_limits<T>::max()) / 4;
   
    vector<T> dist(n, INF);
    dist[s] = 0;
    queue<int> que;
    que.push(s);
    
    while(!que.empty()){
        int at = que.front();
        que.pop();
        for(Edge e: graph[at]){
            if(dist[e.to] == INF){
                dist[e.to] = dist[at] + 1;
                que.push(e.to);
            }
        }
    }
    return dist;
}

template<class T>
vector<T> BFS01(Graph<T> graph, int s){
    int n = int(graph.size());
    T INF = (numeric_limits<T>::max()) / 4;
    
    vector<T> dist(n, INF);
    dist[s] = 0;
    deque<pair<int, T>> que;
    que.push_back({s, 0});
    
    while(!que.empty()){
        auto top = que.front();
        que.pop_back();
        int at = top.first;
        T cost = top.second;
        if(dist[at] < cost) continue;
        
        for(Edge e: graph[at]){
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
    return dist;
}

template<class T>
vector<T> Dijkstra(Graph<T> graph, int s){
    int n = int(graph.size());
    T INF = (numeric_limits<T>::max()) / 4;
    
    vector<T> dist(n, INF);
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
        
        for(Edge e: graph[at]){
            if(cost + e.cost < dist[e.to]){
                dist[e.to] = dist[at] + e.cost;
                que.push({dist[e.to], e.to});
            }
        }
    }
    return dist;
}
