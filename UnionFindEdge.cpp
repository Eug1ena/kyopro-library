struct UnionFindEdge{
    int sz;
    vector<int> data, edge_cnt;
    
    UnionFindEdge(int n): sz(n), data(n, -1), edge_cnt(n, 0) { }
    
    int find(int k){
        if(data[k] < 0){
            return k;
        }else{
            return data[k] = find(data[k]);
        }
    }
    
    void unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b){
            edge_cnt[a]++;
            return;
        }
        if(-data[a] < -data[b]){
            swap(a, b);
        }
        data[a] += data[b];
        edge_cnt[a] += edge_cnt[b] + 1;
        data[b] = a;
    }
    
    int size(int k){
        return -data[find(k)];
    }
    
    int edge_count(int k){
        return edge_cnt[find(k)];
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
};

// verify: https://atcoder.jp/contests/arc111/submissions/19296389
