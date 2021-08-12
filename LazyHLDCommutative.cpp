template<class T, class Op = T>
struct LazySegmentTree{
    using F = function<T(T, T)>;
    using G = function<T(T, Op)>;
    using H = function<Op(Op, Op)>;
    using P = function<Op(Op, int)>;
    
    int sz;
    vector<T> data;
    vector<Op> lazy;
    vector<bool> is_lazy;
    
    F f;
    G g;
    H h;
    P p;
    T id;
    
    LazySegmentTree() { }
    
    LazySegmentTree(int n, F f, G g, H h, P p, T id): f(f), g(g), h(h), p(p), id(id) {
        sz = 1;
        while(sz < n) sz *= 2;
        data.resize(sz * 2, id);
        lazy.resize(sz * 2);
        is_lazy.resize(sz * 2, false);
    }
    
    void set(int k, T x){
        data[k + sz] = x;
    }
    
    void build(){
        repr2(i, 1, sz){
            data[i] = f(data[i * 2], data[i * 2 + 1]);
        }
    }
    
    void eval(int l, int r, int at){
        if(is_lazy[at]){
            data[at] = g(data[at], p(lazy[at], r - l));
            if(r - l > 1){
                lazy[at * 2] = (is_lazy[at * 2] ? h(lazy[at * 2], lazy[at]) : lazy[at]);
                lazy[at * 2 + 1] = (is_lazy[at * 2 + 1] ? h(lazy[at * 2 + 1], lazy[at]) : lazy[at]);
                is_lazy[at * 2] = is_lazy[at * 2 + 1] = true;
            }
            is_lazy[at] = false;
        }
    }
    
    void update(int a, int b, Op x, int l, int r, int at){
        eval(l, r, at);
        if(r <= a || b <= l){
            return;
        }else if(a <= l && r <= b){
            lazy[at] = (is_lazy[at] ? h(lazy[at], x) : x);
            is_lazy[at] = true;
            eval(l, r, at);
            return;
        }
        update(a, b, x, l, (l + r) / 2, at * 2);
        update(a, b, x, (l + r) / 2, r, at * 2 + 1);
        data[at] = f(data[at * 2], data[at * 2 + 1]);
    }
    
    void update(int a, int b, Op x){
        update(a, b, x, 0, sz, 1);
    }
    
    T query(int a, int b, int l, int r, int at){
        eval(l, r, at);
        if(r <= a || b <= l){
            return id;
        }else if(a <= l && r <= b){
            return data[at];
        }
        return f(query(a, b, l, (l + r) / 2, at * 2), query(a, b, (l + r) / 2, r, at * 2 + 1));
    }
    
    T query(int a, int b){
        return query(a, b, 0, sz, 1);
    }
};

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

template<class T, class Op = T>
struct LazyHLDCommutative{
    using F = function<T(T, T)>;
    using G = function<T(T, Op)>;
    using H = function<Op(Op, Op)>;
    using P = function<Op(Op, int)>;
    
    F f;
    G g;
    H h;
    P p;
    T id;
    
    int sz;
    LazySegmentTree<T, Op> seg;
    
    vector<vector<int>> graph;
    vector<vector<int>> child;
    vector<int> size, depth, par;
    vector<int> in, head;
    
    vector<int> tour, tour_id;
    SegmentTree<int> rmq;
    
    LazyHLDCommutative(int n, F f, G g, H h, P p, T id): sz(n), f(f), g(g), h(h), p(p), id(id), graph(n), child(n), size(n), depth(n), par(n), in(n), head(n), tour_id(n) {
        seg = LazySegmentTree<T, Op>(n, f, g, h, p, id);
    }
    
    void add_edge(int a, int b){
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    void dfs_sz(int at, int back){
        size[at] = 1;
        par[at] = back;
        for(int to: graph[at]){
            if(to == back) continue;
            
            depth[to] = depth[at] + 1;
            dfs_sz(to, at);
            child[at].push_back(to);
            size[at] += size[to];
        }
    }
    
    void dfs_hl(int at, int par, int &num){
        in[at] = num;
        num++;
        if(child[at].empty()) return;
        
        for(int &c: child[at]){
            if(size[c] > size[child[at][0]]){
                swap(c, child[at][0]);
            }
        }
        int heavy = child[at][0];
        for(int c: child[at]){
            if(c == heavy){
                head[c] = head[at];
            }else{
                head[c] = c;
            }
            dfs_hl(c, at, num);
        }
    }
    
    void dfs_lca(int at, int back){
        tour_id[at] = int(tour.size());
        tour.push_back(at);
    
        for(int to: graph[at]){
            if(to == back) continue;
            
            dfs_lca(to, at);
            tour.push_back(at);
        }
    }
    
    void build(){
        depth.resize(sz);
        depth[0] = 0;
        dfs_sz(0, -1);
        
        head[0] = 0;
        int tmp = 0;
        dfs_hl(0, -1, tmp);
        
        tour.clear();
        dfs_lca(0, -1);
        
        depth.push_back(INT_MAX);
        auto f = [&](int a, int b){ if(depth[a] < depth[b]) return a; else return b; };
        rmq = SegmentTree<int>(int(tour.size()), f, sz);
        rep(i, tour.size()){
            rmq.update(i, tour[i]);
        }
    }
    
    // s -> t, [s, t)
    T query_up(int s, int t){
        if(s == t) return id;
        T ans = id;
        while(depth[head[s]] > depth[t]){
            int top = head[s];
            ans = f(ans, seg.query(in[top], in[s] + 1));
            s = par[top];
        }
        ans = f(ans, seg.query(in[t] + 1, in[s] + 1));
        return ans;
    }
    
    // s -> t, (s, t]
    T query_down(int s, int t){
        return query_up(t, s);
    }
    
    int lca(int a, int b){
        if(tour_id[a] > tour_id[b]) swap(a, b);
        return rmq.query(tour_id[a], tour_id[b] + 1);
    }
    
    // s -> t, [s, t]
    T query(int s, int t, bool is_edge = false){
        int l = lca(s, t);
        
        T ans = query_up(s, l);
        if(!is_edge) ans = f(ans, seg.query(in[l], in[l] + 1));
        ans = f(ans, query_down(l, t));
        return ans;
    }

    // s -> t, [s, t)
    void update_up(int s, int t, T x){
        if(s == t) return;
        while(depth[head[s]] > depth[t]){
            int top = head[s];
            seg.update(in[top], in[s] + 1, x);
            s = par[top];
        }
        seg.update(in[t] + 1, in[s] + 1, x);
    }
    
    // [s, t]
    void update(int s, int t, T x, bool is_edge = false){
        int l = lca(s, t);
        update_up(s, l, x);
        if(!is_edge) seg.update(in[l], in[l] + 1, x);
        update_up(t, l, x);
    }
};
