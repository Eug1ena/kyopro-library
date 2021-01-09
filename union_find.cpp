struct union_find{
    vector<int> data;
    
    union_find(int n){
        data.resize(n, -1);
    }
    
    int find(int k){
        if(data[k] < 0){
            return k;
        }else{
            return data[k] = find(data[k]);
        }
    }
    
    void unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return;
        if(-data[a] < -data[b]){
            swap(a, b);
        }
        data[a] += data[b];
        data[b] = a;
    }
    
    bool is_group(int a, int b){
        return find(a) == find(b);
    }
};
