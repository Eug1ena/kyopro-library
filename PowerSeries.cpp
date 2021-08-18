template<class T>
struct PowerSeries{
    int sz;
    vector<T> data;
    
    PowerSeries() = default;
    PowerSeries(int sz): sz(sz), data(sz, 0) {}
    PowerSeries(int sz, vector<T> a): sz(sz), data(sz, 0) {
        rep(i, min(sz, a.size())){
            data[i] = a[i];
        }
    }
    
    PowerSeries operator +(PowerSeries a){ return PowerSeries(*this) += a; }
    PowerSeries operator -(PowerSeries a){ return PowerSeries(*this) -= a; }
    PowerSeries operator *(PowerSeries a){ return PowerSeries(*this) *= a; }
    
    PowerSeries operator -(){ return PowerSeries(sz) - PowerSeries(*this); }
    
    PowerSeries& operator +=(PowerSeries a){
        sz = max(sz, a.sz);
        while(data.size() < sz) data.push_back(0);
        rep(i, a.sz){
            data[i] += a[i];
        }
        return *this;
    }
    
    PowerSeries& operator -=(PowerSeries a){
        sz = max(sz, a.sz);
        while(data.size() < sz) data.push_back(0);
        rep(i, a.sz){
            data[i] -= a[i];
        }
        return *this;
    }
    
    PowerSeries& operator *=(PowerSeries a){
        PowerSeries ans(sz + a.sz - 1);
        rep(i, sz){
            rep(j, a.sz){
                ans[i + j] += data[i] * a[j];
            }
        }
        (*this) = ans;
        return *this;
    }
    
    void divide_by_1_x(){
        rep(i, sz - 1){
            data[i + 1] += data[i];
        }
    }
    
    void divide_by_1_xk(int k){
        rep(i, sz - k){
            data[i + k] += data[i];
        }
    }
    
    void multiply_xk(int k){
        repr(i, sz - k){
            data[i + k] = data[i];
        }
        rep(i, k){
            data[i] = 0;
        }
    }
    
    T& operator [](int k){
        return data[k];
    }
};
