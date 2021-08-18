//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using lint = long long;
constexpr lint mod = 998244353;
#define all(x) (x).begin(), (x).end()
#define bitcount(n) __builtin_popcountll((lint)(n))
#define fcout cout << fixed << setprecision(15)
#define highest(x) (63 - __builtin_clzll(x))
#define rep(i, n) for(int i = 0; i < int(n); i++)
#define rep2(i, l, r) for(int i = int(l); i < int(r); i++)
#define repr(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define repr2(i, l, r) for(int i = int(r) - 1; i >= int(l); i--)
#define mp(x, y) make_pair(x, y)
constexpr int inf9 = 1e9; constexpr lint inf18 = 1e18;
inline void Yes(bool condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
lint power(lint base, lint exponent, lint module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ lint root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
template<class itr> void array_output(itr start, itr goal){ for(auto i = start; i != goal; i++) cout << (i == start ? "" : " ") << (*i); cout << endl; }
template<class itr> void cins(itr first, itr last){ for(auto i = first; i != last; i++){ cin >> (*i); } }
template<class T> T gcd(T a, T b){ if(b) return gcd(b, a % b); else return a; }
template<class T> T lcm(T a, T b){ return a / gcd(a, b) * b; }
namespace combination{ vector<lint> fact, factinv;  lint get_inv(lint x){ lint a = 1, exp = mod - 2; while(exp){ if(exp % 2) a = (a * x) % mod; x = (x * x) % mod; exp /= 2; } return a; } void combination_init(int sz){ fact.resize(sz + 1); factinv.resize(sz + 1); fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } factinv[sz] = get_inv(fact[sz]); for(int i = sz - 1; i >= 0; i--){ factinv[i] = factinv[i + 1] * (i + 1) % mod; } } lint P(int n, int r){ if(r < 0 || n < r) return 0; return (fact[n] * factinv[n - r] % mod); } lint C(int p, int q){ if(q < 0 || p < q) return 0; return (fact[p] * factinv[q] % mod * factinv[p - q] % mod); } };
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b){ if(b < a){ a = b; return 1; } return 0; }
inline int at(lint i, int j){ return (i >> j) & 1; }
bool is_inside(lint y, lint x, lint H, lint W){ return (0 <= y && y < H && 0 <= x && x < W); }

struct io_init {
   io_init() {
     cin.tie(nullptr); cout.tie(nullptr);
     std::ios::sync_with_stdio(false);
   }
} io_init;

int main(){
    
}
