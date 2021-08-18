struct Modint{
    lint x;
    
    Modint(): x(0) {}
    Modint(lint x): x(x >= 0 || x % mod == 0 ? x % mod : mod - (-x) % mod) {}
    
    Modint operator +(Modint a){ return Modint(*this) += a; }
    Modint operator -(Modint a){ return Modint(*this) -= a; }
    Modint operator *(Modint a){ return Modint(*this) *= a; }
    Modint operator /(Modint a){ return Modint(*this) /= a; }
    
    Modint operator -(){ return Modint(0) - Modint(*this); }
    
    Modint& operator +=(Modint a){
        x += a.x;
        if(x >= mod) x -= mod;
        return *this;
    }
    
    Modint& operator -=(Modint a){
        if(x < a.x) x += mod;
        x -= a.x;
        return *this;
    }
    
    Modint& operator *=(Modint a){
        x = x * a.x % mod;
        return *this;
    }
    
    Modint& operator /=(Modint a){
        (*this) *= a.inv();
        return *this;
    }
    
    Modint inv(){
        return pow(mod - 2);
    }
    
    Modint pow(lint exp){
        Modint ans(1), powed = (*this);
        while(exp){
            if(exp % 2) ans *= powed;
            powed *= powed;
            exp /= 2;
        }
        return ans;
    }
    
    bool operator ==(Modint a){ return x == a.x; }
    bool operator !=(Modint a){ return x != a.x; }
};

ostream& operator <<(ostream& os, Modint a){
    os << a.x;
    return os;
}

istream &operator >>(istream &is, Modint& a){
    lint x;
    is >> x;
    a = Modint(x);
    return is;
}

