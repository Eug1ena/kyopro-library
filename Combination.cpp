struct Combination{
    vector<lint> fact, inv;
    
    lint get_inv(lint x){
        lint a = 1, exp = mod - 2;
        while(exp){
            if(exp % 2) a = (a * x) % mod;
            x = (x * x) % mod;
            exp /= 2;
        } return a;
    }
    
    Combination(int sz){
        fact.resize(sz + 1);
        inv.resize(sz + 1);
        fact[0] = 1;
        for(int i = 1; i <= sz; i++){
            fact[i] = fact[i - 1] * i % mod;
            
        }
        inv[sz] = get_inv(fact[sz]);
        for(int i = sz - 1; i >= 0; i--){
            inv[i] = inv[i + 1] * (i + 1) % mod;
            
        }
    }
    
    lint P(int n, int r){
        if(r < 0 || n < r) return 0;
        return (fact[n] * inv[n - r] % mod);
    }
    
    lint C(int n, int r){
        if(r < 0) return 0;
        return P(n, r) * inv[r] % mod;
    }
    
    lint H(int n, int r){
        return C(n + r - 1, r);
    }
} comb(1e5);
