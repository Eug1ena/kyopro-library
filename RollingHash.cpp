struct RollingHash{
    const int base = 1e8;
    const lint module = 1e9 + 7;
    
    int sz;
    vector<lint> data;
    vector<lint> pow, powinv;
    
    RollingHash(string s){
        sz = int(s.size());
        
        pow.assign(sz, 1);
        powinv.assign(sz, 1);
        lint baseinv = inv(base);
        rep(i, sz - 1){
            pow[i + 1] = (pow[i] * base) % module;
            powinv[i + 1] = (powinv[i] * baseinv) % module;
        }
        
        data.resize(sz + 1);
        data[0] = 0;
        rep(i, sz){
            data[i + 1] = (data[i] + s[i] * pow[i]) % module;
        }
    }
    
    lint inv(lint x){
        lint ans = 1, exp = module - 2;
        while(exp){
            if(exp % 2) ans = (ans * x) % module;
            x = (x * x) % module;
            exp /= 2;
        }
        
        return ans;
    }
    
    lint get(int l, int r){ // [l, r)
        return (data[r] - data[l] + module) * powinv[l] % module;
    }
};
