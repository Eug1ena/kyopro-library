struct BinaryIndexedTree{
    int sz;
    vector<lint> data;
    
    BinaryIndexedTree(int n): sz(n), data(n + 1, 0) {}
    
    void add(int k, lint x){
        k++;
        for(int i = k; i <= sz; i += (i & -i)){
            data[i] += x;
        }
    }
    
    lint query(int r){ // [0, r)
        lint ret = 0;
        for(int i = r; i >= 1; i -= (i & -i)){
            ret += data[i];
        }
        return ret;
    }
};

lint InversionNumber(vector<int> a){
    int n = int(a.size());

    vector<pair<int, int>> a2(n);
    rep(i, n){
        a2[i] = {a[i], i};
    }
    sort(all(a2), greater<>());
    
    BinaryIndexedTree bit(n);
    lint ans = 0;
    for(auto v: a2){
        int at = v.second;
        ans += bit.query(at);
        bit.add(at, 1);
    }
    
    return ans;
}
