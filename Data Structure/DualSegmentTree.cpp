template<class T>
struct DualSegmentTree{
    using F = function<T(T, T)>;
    
    int sz, height;
    vector<T> data;
    vector<bool> is_data;
    
    F f;
    T id;
    
    DualSegmentTree() = default;
    DualSegmentTree(int n, F f): f(f) {
        sz = 1;
        height = 0;
        while(sz < n) sz *= 2, height++;
        data.resize(sz * 2, id);
        is_data.resize(sz * 2, false);
    }
    
    void set(int k, T x){
        k += sz;
        data[k] = x;
        is_data[k] = true;
    }
    
    void eval(int at){
        if(is_data[at]){
            data[at * 2] = is_data[at * 2] ? f(data[at * 2], data[at]) : data[at];
            data[at * 2 + 1] = is_data[at * 2 + 1] ? f(data[at * 2 + 1], data[at]) : data[at];
            is_data[at * 2] = true;
            is_data[at * 2 + 1] = true;
            
            is_data[at] = false;
        }
    }
    
    void update(int a, int b, T x, int l, int r, int at){
        if(r <= a || b <= l) return;
        if(a <= l && r <= b){
            data[at] = (is_data[at] ? f(data[at], x) : x);
            is_data[at] = true;
            return;
        }
        
        eval(at);
        int mid = (l + r) / 2;
        update(a, b, x, l, mid, at * 2);
        update(a, b, x, mid, r, at * 2 + 1);
    }
    
    void update(int a, int b, T x){
        update(a, b, x, 0, sz, 1);
    }
    
    T operator [](int k){
        k += sz;
        repr(i, height){
            eval(k >> (i + 1));
        }
        return data[k];
    }
};
