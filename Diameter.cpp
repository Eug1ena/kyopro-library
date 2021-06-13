namespace Diameter{
vector<vector<int>> graph;
vector<int> dist;

void dfs(int at, int back, int dist_now){
    dist[at] = dist_now;
    for(int to: graph[at]){
        if(to == back) continue;
        dfs(to, at, dist_now + 1);
    }
}

int getDiameter(vector<vector<int>> g){
    int sz = int(g.size());
    graph = g;
    
    dist.resize(sz);
    dfs(0, -1, 0);
    int u = int(max_element(all(dist)) - dist.begin());
    
    dfs(u, -1, 0);
    return *max_element(all(dist));
}

};
