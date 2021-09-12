template<class T>
struct SparseTable{
    using F = function<T(T, T)>;
    F f;
    
    int sz;
    vector<vector<T>> data;
    vector<int> logs;
    
    SparseTable(vector<T> a, F f): f(f) {
        sz = int(a.size());
        
        logs.resize(sz + 1);
        logs[0] = -1;
        rep2(i, 1, sz + 1) logs[i] = logs[i / 2] + 1;
        
        data.resize(logs[sz] + 1);
        data[0].resize(sz);
        rep(i, sz){
            data[0][i] = a[i];
        }
        rep2(i, 1, logs[sz] + 1){
            int len = sz + 1 - (1 << i);
            data[i].resize(len);
            rep(j, len){
                data[i][j] = f(data[i - 1][j], data[i - 1][j + (1 << i) / 2]);
            }
        }
    }
    
    T query(int l, int r){
        int lg = logs[r - l];
        return f(data[lg][l], data[lg][r - (1 << lg)]);
    }
};
