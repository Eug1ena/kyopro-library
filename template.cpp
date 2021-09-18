//#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using lint = long long;
constexpr lint mod = 1e9 + 7;
#define all(x) begin(x), end(x)
#define bitcount(n) __builtin_popcountll((lint)(n))
#define fcout cout << fixed << setprecision(15)
#define highest(x) (63 - __builtin_clzll(x))
#define rep(i, n) for(int i = 0; i < int(n); i++)
#define rep2(i, l, r) for(int i = int(l); i < int(r); i++)
#define repr(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define repr2(i, l, r) for(int i = int(r) - 1; i >= int(l); i--)
constexpr int inf9 = 1e9; constexpr lint inf18 = 1e18;
inline void Yes(bool condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class itr> void array_output(itr start, itr goal){ for(auto i = start; i != goal; i++) cout << (i == start ? "" : " ") << (*i); cout << endl; }
template<class itr> void cins(itr first, itr last){ for(auto i = first; i != last; i++){ cin >> (*i); } }
template<class T> T gcd(T a, T b){ if(b) return gcd(b, a % b); else return a; }
template<class T> T lcm(T a, T b){ return a / gcd(a, b) * b; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b){ if(b < a){ a = b; return 1; } return 0; }
inline int has(lint i, int j){ return (i >> j) & 1; }
int dy[4] = {1, 0, -1, 0}; int dx[4] = {0, 1, 0, -1};
bool is_inside(lint y, lint x, lint H, lint W){ return (0 <= y && y < H && 0 <= x && x < W); }

struct io_init {
   io_init() {
     cin.tie(nullptr); cout.tie(nullptr);
     std::ios::sync_with_stdio(false);
   }
} io_init;

int main(){
    
}
