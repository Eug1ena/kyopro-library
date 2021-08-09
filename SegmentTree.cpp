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
