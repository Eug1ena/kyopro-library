vector<int> ShiftsArray(string s){
    int n = int(s.size());
    
    vector<int> cnt(256, 0);
    rep(i, n){
        cnt[s[i]]++;
    }
    rep2(i, 1, 256){
        cnt[i] += cnt[i - 1];
    }
    vector<int> SA(n), rank(n); // SA := 2^k文字目までのSA, rank := SAにおいて何番目か(重複は同順位)
    rep(i, n){
        cnt[s[i]]--;
        SA[cnt[s[i]]] = i;
    }
    
    rank[SA[0]] = 0;
    rep(i, n - 1){
        int a = SA[i], b = SA[i + 1];
        rank[b] = rank[a] + (s[a] != s[b]);
    }
    
    int len = 1;
    while(len < n){
        vector<int> SA2(n), rank2(n);
        rep(i, n) SA2[i] = i;
        
        rep(i, n){
            SA2[i] = SA[i] - len;
            if(SA2[i] < 0) SA2[i] += n;
        }
        cnt = vector<int>(n, 0);
        rep(i, n){
            cnt[rank[SA2[i]]]++;
        }
        rep2(i, 1, n){
            cnt[i] += cnt[i - 1];
        }
        repr(i, n){
            cnt[rank[SA2[i]]]--;
            SA[cnt[rank[SA2[i]]]] = SA2[i];
        }
        
        rank2[SA[0]] = 0;
        rep(i, n - 1){
            int a = SA[i], b = SA[i + 1];
            rank2[b] = rank2[a] + (rank[a] != rank[b] || rank[(a + len) % n] != rank[(b + len) % n]);
        }
        rank = rank2;
        
        len *= 2;
    }
    return SA;
}

vector<int> SuffixArray(string s){
    s.push_back(0);
    vector<int> ans = ShiftsArray(s);
    ans.erase(ans.begin());
    return ans;
}
