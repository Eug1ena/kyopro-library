struct SegtreeRUQRMQ{
    int sz;
    vector<int> data, lazy;
    vector<bool> is_lazy;
    
    SegtreeRUQRMQ(int n){
        sz = 1;
        while(sz < n) sz *= 2;
        data.resize(sz * 2, INT_MAX);
        lazy.resize(sz * 2, INT_MAX);
        is_lazy.resize(sz * 2, false);
    }
    
    void eval(int l, int r, int now){
        if(is_lazy[now]){
            data[now] = lazy[now];
            is_lazy[now] = false;
            if(r - l > 1){
                lazy[now * 2] = lazy[now];
                lazy[now * 2 + 1] = lazy[now];
                is_lazy[now * 2] = true;
                is_lazy[now * 2 + 1] = true;
            }
        }
    }
    
    void update(int a, int b, int x, int l, int r, int now){
        eval(l, r, now);
        if(r <= a || b <= l){
            return;
        }
        if(a <= l && r <= b){
            lazy[now] = x;
            is_lazy[now] = true;
            eval(l, r, now);
            return;
        }
        update(a, b, x, l, (l + r) / 2, now * 2);
        update(a, b, x, (l + r) / 2, r, now * 2 + 1);
        data[now] = min(data[now * 2], data[now * 2 + 1]);
    }
    
    void update(int a, int b, int x){
        update(a, b, x, 0, sz, 1);
    }
    
    int query(int a, int b, int l, int r, int now){
        eval(l, r, now);
        if(r <= a || b <= l){
            return INT_MAX;
        }
        if(a <= l && r <= b){
            return data[now];
        }
        return min(query(a, b, l, (l + r) / 2, now * 2), query(a, b, (l + r) / 2, r, now * 2 + 1));
    }
    
    int query(int a, int b){
        return query(a, b, 0, sz, 1);
    }
};
