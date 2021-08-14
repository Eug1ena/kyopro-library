namespace DiameterWork{
    Graph graph;

    pair<int, int> dfs(int at, int back){
        pair<int, int> ret = {0, at};
        for(int to: graph[at]){
            if(to == back) continue;
            
            auto x = dfs(to, at);
            x.first++;
            ret = max(ret, x);
        }
        return ret;
    }
}

int Diameter(Graph<int> &g){
    DiameterWork::graph = g;

    int u = DiameterWork::dfs(0, -1).second;
    return DiameterWork::dfs(u, -1).first;
}
