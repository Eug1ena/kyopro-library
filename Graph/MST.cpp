struct UnionFind{
    int sz;
    vector<int> data;
    
    UnionFind(int n): sz(n), data(n, -1) { }
    
    int find(int k){
        if(data[k] < 0){
            return k;
        }else{
            return data[k] = find(data[k]);
        }
    }
    
    bool unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return false;
        if(-data[a] < -data[b]){
            swap(a, b);
        }
        data[a] += data[b];
        data[b] = a;
        return true;
    }
};

template<class T>
Graph<T> MST(Graph<T> g){
    int n = g.size();
    
    Edges<T> edges;
    rep(at, n) for(auto e: g[at]){
        edges.push_back(e);
    }
    
    sort(all(edges), [](Edge<T> e1, Edge<T> e2){ return e1.cost < e2.cost; });
    
    UnionFind uf(n);
    Graph<T> g_ret(n);
    for(auto e: edges){
        if(uf.unite(e.from, e.to)){
            g_ret.add_edge(e.from, e.to, e.cost);
        }
    }
    
    return g_ret;
}
