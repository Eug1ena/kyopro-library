namespace FWHT{
    template<class T>
    vector<T> FWHT(vector<T> &vec){
        int n = int(vec.size());
        if(n == 1) return vec;
        
        vector<T> vec1, vec2;
        rep(i, n / 2){
            vec1.push_back(vec[i]);
            vec2.push_back(vec[i + n / 2]);
        }
        
        auto res1 = FWHT(vec1), res2 = FWHT(vec2);
        vector<T> res(n);
        rep(i, n / 2){
            res[i] = res1[i] + res2[i];
            res[i + n / 2] = res1[i] - res2[i];
        }
        return res;
    }

    template<class T>
    vector<T> XorConvolution(vector<T> a, vector<T> b){
        int n = int(a.size());
        
        vector<T> a2 = FWHT(a), b2 = FWHT(b);
        vector<T> mul(n);
        rep(i, n) mul[i] = a2[i] * b2[i];
        
        vector<T> ans = FWHT(mul);
        rep(i, n) ans[i] /= n;
        
        return ans;
    }
}
