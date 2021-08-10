struct SegmentTreeBeats{
    const lint inf = 1e18;
    int sz;
    vector<lint> sum;
    vector<lint> max1, max2, max_cnt;
    vector<lint> min1, min2, min_cnt;
    vector<lint> lazy;
    vector<lint> len;
    
    SegmentTreeBeats(int n, vector<lint> &a){
        sz = 1;
        while(sz < n) sz *= 2;
        
        sum.resize(sz * 2);
        max1.resize(sz * 2);
        max2.resize(sz * 2);
        max_cnt.resize(sz * 2);
        min1.resize(sz * 2);
        min2.resize(sz * 2);
        min_cnt.resize(sz * 2);
        lazy.resize(sz * 2, 0);
        len.resize(sz * 2, 1);
        rep(i, n){
            sum[i + sz] = a[i];
            max1[i + sz] = a[i];
            max2[i + sz] = -inf;
            max_cnt[i + sz] = 1;
            min1[i + sz] = a[i];
            min2[i + sz] = inf;
            min_cnt[i + sz] = 1;
        }
        rep2(i, n, sz){
            sum[i + sz] = 0;
            max1[i + sz] = -inf;
            max2[i + sz] = -inf;
            max_cnt[i + sz] = 1;
            min1[i + sz] = inf;
            min2[i + sz] = inf;
            min_cnt[i + sz] = 1;
        }
        repr2(i, 1, sz){
            update_node(i);
            len[i] = len[i * 2] * 2;
        }
    }
    
    void pushdown(int l, int r, int at){
        if(r - l > 1){
            add_node(at * 2, lazy[at]);
            add_node(at * 2 + 1, lazy[at]);
            lazy[at] = 0;
            
            if(max1[at * 2] > max1[at]){
                chmin_node(at * 2, max1[at]);
            }
            if(max1[at * 2 + 1] > max1[at]){
                chmin_node(at * 2 + 1, max1[at]);
            }
            
            if(min1[at * 2] < min1[at]){
                chmax_node(at * 2, min1[at]);
            }
            if(min1[at * 2 + 1] < min1[at]){
                chmax_node(at * 2 + 1, min1[at]);
            }
        }
    }
    
    void chmin_node(int at, lint x){
        sum[at] += (x - max1[at]) * max_cnt[at];
        if(max1[at] == min1[at]){
            max1[at] = min1[at] = x;
        }else if(max1[at] == min2[at]){
            max1[at] = min2[at] = x;
        }else{
            max1[at] = x;
        }
    }
    
    void chmax_node(int at, lint x){
        sum[at] += (x - min1[at]) * min_cnt[at];
        if(min1[at] == max1[at]){
            min1[at] = max1[at] = x;
        }else if(min1[at] == max2[at]){
            min1[at] = max2[at] = x;
        }else{
            min1[at] = x;
        }
    }
    
    void add_node(int at, lint x){
        sum[at] += x * len[at];
        if(max1[at] != -inf) max1[at] += x;
        if(min2[at] != -inf) max2[at] += x;
        if(min1[at] != inf) min1[at] += x;
        if(min2[at] != inf) min2[at] += x;
        lazy[at] += x;
    }
    
    void update_node(int at){
        sum[at] = sum[at * 2] + sum[at * 2 + 1];

        if(max1[at * 2] > max1[at * 2 + 1]){
            max1[at] = max1[at * 2];
            max_cnt[at] = max_cnt[at * 2];
            max2[at] = max(max2[at * 2], max1[at * 2 + 1]);
        }else if(max1[at * 2] < max1[at * 2 + 1]){
            max1[at] = max1[at * 2 + 1];
            max_cnt[at] = max_cnt[at * 2 + 1];
            max2[at] = max(max1[at * 2], max2[at * 2 + 1]);
        }else{
            max1[at] = max1[at * 2];
            max_cnt[at] = max_cnt[at * 2] + max_cnt[at * 2 + 1];
            max2[at] = max(max2[at * 2], max2[at * 2 + 1]);
        }
        
        if(min1[at * 2] < min1[at * 2 + 1]){
            min1[at] = min1[at * 2];
            min_cnt[at] = min_cnt[at * 2];
            min2[at] = min(min2[at * 2], min1[at * 2 + 1]);
        }else if(min1[at * 2] > min1[at * 2 + 1]){
            min1[at] = min1[at * 2 + 1];
            min_cnt[at] = min_cnt[at * 2 + 1];
            min2[at] = min(min1[at * 2], min2[at * 2 + 1]);
        }else{
            min1[at] = min1[at * 2];
            min_cnt[at] = min_cnt[at * 2] + min_cnt[at * 2 + 1];
            min2[at] = min(min2[at * 2], min2[at * 2 + 1]);
        }
    }
    
    void chmin(int a, int b, lint x, int l, int r, int at){
        if(r <= a || b <= l || max1[at] <= x){
            return;
        }else if(a <= l && r <= b && max2[at] < x){
            chmin_node(at, x);
            return;
        }
        pushdown(l, r, at);
        chmin(a, b, x, l, (l + r) / 2, at * 2);
        chmin(a, b, x, (l + r) / 2, r, at * 2 + 1);
        update_node(at);
    }
    
    void chmin(int a, int b, lint x){
        chmin(a, b, x, 0, sz, 1);
    }
    
    void chmax(int a, int b, lint x, int l, int r, int at){
        if(r <= a || b <= l || x <= min1[at]){
            return;
        }else if(a <= l && r <= b && x < min2[at]){
            chmax_node(at, x);
            return;
        }
        pushdown(l, r, at);
        chmax(a, b, x, l, (l + r) / 2, at * 2);
        chmax(a, b, x, (l + r) / 2, r, at * 2 + 1);
        update_node(at);
    }
    
    void chmax(int a, int b, lint x){
        chmax(a, b, x, 0, sz, 1);
    }
    
    void add(int a, int b, lint x, int l, int r, int at){
        if(r <= a || b <= l){
            return;
        }else if(a <= l && r <= b){
            add_node(at, x);
            return;
        }
        pushdown(l, r, at);
        add(a, b, x, l, (l + r) / 2, at * 2);
        add(a, b, x, (l + r) / 2, r, at * 2 + 1);
        update_node(at);
    }
    
    void add(int a, int b, lint x){
        add(a, b, x, 0, sz, 1);
    }
    
    lint query_sum(int a, int b, int l, int r, int at){
        if(r <= a || b <= l){
            return 0;
        }else if(a <= l && r <= b){
            return sum[at];
        }
        pushdown(l, r, at);
        return query_sum(a, b, l, (l + r) / 2, at * 2) + query_sum(a, b, (l + r) / 2, r, at * 2 + 1);
    }
    
    lint query_sum(int a, int b){
        return query_sum(a, b, 0, sz, 1);
    }
};
