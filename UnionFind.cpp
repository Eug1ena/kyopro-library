struct UnionFind{
    int sz;
    vector<int> data;
    
    UnionFind(int n): sz(n), data(n, -1) { }
    
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
    
    int size(int k){
        return -data[find(k)];
    }
    
    bool is_group(int a, int b){
        return find(a) == find(b);
    }
    
    vector<int> roots(){
        vector<int> ret;
        rep(i, sz){
            if(data[i] < 0) ret.push_back(i);
        }
        return ret;
    }
    
    vector<vector<int>> groups(){
        vector<vector<int>> group_list(sz);
        rep(i, sz){
            group_list[find(i)].push_back(i);
        }
        
        vector<vector<int>> ret;
        for(auto& vec: group_list){
            if(!vec.empty()){
                ret.push_back(vec);
            }
        }
        return ret;
    }
};
