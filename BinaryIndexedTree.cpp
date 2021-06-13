struct BinaryIndexedTree{
    int sz;
    vector<int> data;
    
    BinaryIndexedTree(int n): sz(n), data(n - 1, 0) {}
    
    void update(int k, int x){
        k++;
        for(int i = k; i <= sz; i += (i & -i)){
            data[i] += x;
        }
    }
    
    int query(int r){ // [0, r)
        int ret = 0;
        for(int i = r; i >= 1; i -= (i & -i)){
            ret += data[i];
        }
        return ret;
    }
};
