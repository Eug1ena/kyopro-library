namespace NTT{

const lint MOD = 998244353; // 119 * 2^23 + 1
const lint ROOT = 15311432; // 3^119
const lint ROOT_INV = 469870224; // 3^(-119)

int bits_msb(int x){
    x = x | (x >> 1);
    x = x | (x >> 2);
    x = x | (x >> 4);
    x = x | (x >> 8);
    x = x | (x >> 16);
    return x ^ (x >> 1);
}

lint power(lint base, lint ex){
    lint ans = 1, mul = base;
    rep(i, 30){
        if(has(ex, i)){
            ans = (ans * mul) % MOD;
        }
        
        mul = (mul * mul) % MOD;
    }
    
    return ans;
}

lint inv(lint x){
    return power(x, MOD - 2);
}
    
vector<lint> dfs(vector<lint> A, bool is_inv = false){
    int n = int(A.size());
    if(n == 1) return A;
    
    lint p = (is_inv ? ROOT_INV : ROOT);
    p = power(p, (1 << 23) / n);
    
    vector<lint> A_even(n / 2), A_odd(n / 2);
    rep(i, n / 2){
        A_even[i] = A[i * 2];
        A_odd[i] = A[i * 2 + 1];
    }
    
    auto DFT_even = dfs(A_even, is_inv);
    auto DFT_odd = dfs(A_odd, is_inv);
    
    vector<lint> B(n);
    lint mul = 1;
    rep(i, n / 2){
        DFT_odd[i] = (DFT_odd[i] * mul) % MOD;
        
        B[i] = (DFT_even[i] + DFT_odd[i]) % MOD;
        B[i + n / 2] = (DFT_even[i] - DFT_odd[i] + MOD) % MOD;
        
        mul = (mul * p) % MOD;
    }
    
    return B;
}

vector<lint> NTT(vector<lint> A, bool is_inv = false){
    int n = int(A.size());
    assert(n == bits_msb(n) && n <= (1 << 23));

    vector<lint> B = dfs(A, is_inv);

    if(is_inv){
        lint n_inv = inv(n);
        for(auto &x: B) x = (x * n_inv) % MOD;
    }
    return B;
}

vector<lint> multiply(vector<lint> A, vector<lint> B){
    int N = int(A.size()) + int(B.size()) - 1;
    for(lint &x: A) x %= MOD;
    for(lint &x: B) x %= MOD;
    
    int N_pow2 = bits_msb(N * 2 - 1);
    while(A.size() < N_pow2) A.push_back(0);
    while(B.size() < N_pow2) B.push_back(0);
    
    auto A_vals = NTT(A);
    auto B_vals = NTT(B);
    vector<lint> C_vals(N_pow2);
    rep(i, N_pow2){
        C_vals[i] = A_vals[i] * B_vals[i] % MOD;
    }
    
    auto C = NTT(C_vals, true);
    while(C.size() > N) C.pop_back();
    return C;
}

}
