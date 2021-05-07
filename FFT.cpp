namespace FFT{
    int bits_msb(int x){
        x = x | (x >> 1);
        x = x | (x >> 2);
        x = x | (x >> 4);
        x = x | (x >> 8);
        x = x | (x >> 16);
        return x ^ (x >> 1);
    }
    
    vector<complex<double>> DFT(vector<complex<double>> f, bool is_inverse){ // DFT_mode: 1 -> DFT, -1 -> Inverse DFT
        double pi = acos(-1.0) * (is_inverse ? 1 : -1);
        int sz = int(f.size());
        vector<complex<double>> polars(sz);
        rep(i, sz){
            polars[i] = polar(1.0, 2.0 * pi * i / sz);
        }
        vector<complex<double>> DFT_segtree(sz); // 1-indexed, inline segtree
        rep(i, sz){
            int number = 0;
            for(int j = 0; (1 << j) < sz; j++){
                number |= ((i >> j) & 1) * (sz >> (j + 1));
            }
            DFT_segtree[i] = f[number];
        }
        repr2(i, 1, sz){
            int segment_size = sz / bits_msb(i);
            int left_pos = (i - bits_msb(i)) * segment_size;
            rep(j, segment_size / 2){
                auto f0 = DFT_segtree[left_pos + j], f1 = DFT_segtree[left_pos + j + segment_size / 2];
                DFT_segtree[left_pos + j] = f0 + f1 * polars[j * bits_msb(i)];
                DFT_segtree[left_pos + j + segment_size / 2] = f0 + f1 * polars[j * bits_msb(i) + sz / 2];
            }
        }
        if(is_inverse){
            rep(i, sz){
                DFT_segtree[i] /= sz;
            }
        }
        return DFT_segtree;
    }
    
    vector<lint> multiply(vector<int> a, vector<int> b){
        int sz = 1;
        while(sz + 2 <= a.size() + b.size()){
            sz *= 2;
        }
        vector<complex<double>> a_complex(sz), b_complex(sz);
        rep(i, a.size()){
            a_complex[i] = a[i];
        }
        rep(i, b.size()){
            b_complex[i] = b[i];
        }
        auto DFTed_a = DFT(a_complex, false), DFTed_b = DFT(b_complex, false);
        vector<complex<double>> DFTed_mul(sz);
        rep(i, sz){
            DFTed_mul[i] = DFTed_a[i] * DFTed_b[i];
        }
        vector<complex<double>> mul = DFT(DFTed_mul, true);
        vector<lint> ret(sz);
        rep(i, sz){
            ret[i] = mul[i].real() + 0.5;
        }
        return ret;
    }
}
