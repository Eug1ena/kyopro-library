template<class T>
struct Matrix{
    int h, w;
    vector<vector<T>> data;
    
    Matrix(int n) : h(n), w(n), data(n, vector<T>(n)){};
    Matrix(int h, int w) : h(h), w(w), data(h, vector<T>(w)){};
    
    Matrix operator +(Matrix a){ return Matrix(*this) += a; }
    Matrix operator -(Matrix a){ return Matrix(*this) -= a; }
    Matrix operator *(Matrix a){ return Matrix(*this) *= a; }
    
    Matrix& operator +=(Matrix a){
        rep(i, h) rep(j, w){
            data[i][j] += a[i][j];
        }
        return *this;
    }
    
    Matrix& operator -=(Matrix a){
        rep(i, h) rep(j, w){
            data[i][j] -= a[i][j];
        }
        return *this;
    }
    
    Matrix& operator *=(Matrix a){
        Matrix ans(h, a.w);
        rep(i, h) rep(j, a.w){
            ans[i][j] = 0;
            rep(k, w){
                ans[i][j] += data[i][k] * a[k][j];
            }
        }
        (*this) = ans;
        return *this;
    }
    
    vector<T>& operator [](int k){
        return data[k];
    }
    
    Matrix pow(lint exp){
        Matrix ans(1), powed = (*this);
        while(exp){
            if(exp % 2) ans *= powed;
            powed *= powed;
            exp /= 2;
        }
        return ans;
    }
};
