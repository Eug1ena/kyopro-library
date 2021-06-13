struct SegmentTree{
    int sz;
    vector<int> data;
    
    SegmentTree(int n){
        sz = 1;
        while(sz < n) sz *= 2;
        data.resize(sz * 2, 1e9);
    }
    
    void update(int k, int x){
        k += sz;
        data[k] = x;
        while(k > 1){
            k /= 2;
            data[k] = min(data[k * 2], data[k * 2 + 1]);
        }
    }
    
    int query(int a, int b, int l, int r, int at){
        if(a <= l && r <= b){
            return data[at];
        }else if(r <= a || b <= l){
            return 1e9;
        }
        return min(query(a, b, l, (l + r) / 2, at * 2), query(a, b, (l + r) / 2, r, at * 2 + 1));
    }
    
    int query(int a, int b){
        return query(a, b, 0, sz, 1);
    }
};
