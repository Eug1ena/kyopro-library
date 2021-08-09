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
