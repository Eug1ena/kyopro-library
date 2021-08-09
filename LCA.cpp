template<class T>
struct SegmentTree{
    using F = function<T(T, T)>;
    
    int sz;
    vector<T> data;
    
    F f;
    T id;
    
    SegmentTree(): sz(1), f([](T a, T b){ return a + b; }), data(2, id) {}
    
    SegmentTree(int n, F f, T id): f(f), id(id) {
        sz = 1;
        while(sz < n) sz *= 2;
        data.resize(sz * 2, id);
    }
    
    void update(int k, T x){
        k += sz;
        data[k] = x;
        while(k > 1){
            k /= 2;
            data[k] = f(data[k * 2], data[k * 2 + 1]);
        }
    }
    
    T query(int a, int b, int l, int r, int at){
        if(a <= l && r <= b){
            return data[at];
        }else if(r <= a || b <= l){
            return id;
        }
        return f(query(a, b, l, (l + r) / 2, at * 2), query(a, b, (l + r) / 2, r, at * 2 + 1));
    }
    
    T query(int a, int b){
        return query(a, b, 0, sz, 1);
    }
    
    T operator [](int k){
        return data[k + sz];
    }
};

struct LCA{
    int sz;
    vector<vector<int>> graph;
    
    vector<vector<int>> child;
    vector<int> tour, depth, id;
    
    SegmentTree<int> rmq;
    
    void dfs(int at, int back){
        id[at] = int(tour.size());
        tour.push_back(at);
    
        for(int to: graph[at]){
            if(to == back) continue;
            
            depth[to] = depth[at] + 1;
            child[at].push_back(to);
            dfs(to, at);
            
            tour.push_back(at);
        }
    }
    
    LCA(int n): sz(n), graph(n) {}
    
    void add_edge(int a, int b){
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    void build(){
        tour.clear();
        child = vector<vector<int>>(sz);
        depth = vector<int>(sz);
        id = vector<int>(sz);
        
        depth[0] = 0;
        dfs(0, -1);
        
        depth.push_back(INT_MAX);
        auto f = [&](int a, int b){ if(depth[a] < depth[b]) return a; else return b; };
        rmq = SegmentTree<int>(int(tour.size()), f, sz);
        rep(i, tour.size()){
            rmq.update(i, tour[i]);
        }
    }
    
    int dist(int a, int b){
        if(id[a] > id[b]) swap(a, b);
        return rmq.query(id[a], id[b] + 1);
    }
};
