struct RollingHash{
    using ulint = unsigned long long;
    const ulint MASK30 = (1ull << 30) - 1;
    const ulint MASK31 = (1ull << 31) - 1;
    const ulint MASK61 = (1ull << 61) - 1;
    const ulint MOD = MASK61;
    
    const int base = 1e8;
    // mod = 2^61 - 1
    
    int sz;
    vector<ulint> data;
    vector<ulint> pow, powinv;
    
    ulint modulo(ulint x){
        ulint xu = (x >> 61);
        ulint xd = x & MASK61;
        ulint res = xu + xd;
        if(res >= MOD){
            res -= MOD;
        }
        return res;
    }
    
    ulint mul(ulint a, ulint b){
        ulint au = (a >> 31);
        ulint ad = a & MASK31;
        ulint bu = (b >> 31);
        ulint bd = b & MASK31;
        
        ulint mid = au * bd + ad * bu;
        ulint midu = (mid >> 30);
        ulint midd = mid & MASK30;
        
        return modulo(au * bu * 2 + midu + (midd << 31) + ad * bd);
    }
    
    RollingHash() = default;
    RollingHash(string s){
        set(s);
    }
    
    void set(string s){
        sz = int(s.size());
        
        pow.assign(sz, 1);
        powinv.assign(sz, 1);
        ulint baseinv = inv(base);
        rep(i, sz - 1){
            pow[i + 1] = mul(pow[i], base);
            powinv[i + 1] = mul(powinv[i], baseinv);
        }
        
        data.resize(sz + 1);
        data[0] = 0;
        rep(i, sz){
            data[i + 1] = modulo(data[i] + mul(s[i], pow[i]));
        }
    }
    
    ulint inv(ulint x){
        ulint ans = 1, exp = MOD - 2;
        while(exp){
            if(exp % 2) ans = mul(ans, x);
            x = mul(x, x);
            exp /= 2;
        }
        
        return ans;
    }
    
    ulint get(int l, int r){ // [l, r)
        return mul(modulo(data[r] - data[l] + MOD), powinv[l]);
    }
    
    ulint get(){
        return get(0, sz);
    }
    
    int size(){
        return sz;
    }
};
