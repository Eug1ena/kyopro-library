template<class T>
struct BinaryIndexedTree{
    int sz;
    vector<T> data;
    
    BinaryIndexedTree(int n): sz(n), data(n + 1, 0) {}
    
    void add(int k, T x){
        k++;
        for(int i = k; i <= sz; i += (i & -i)){
            data[i] += x;
        }
    }
    
    T query(int r){ // [0, r)
        T ret = 0;
        for(int i = r; i >= 1; i -= (i & -i)){
            ret += data[i];
        }
        return ret;
    }
};
