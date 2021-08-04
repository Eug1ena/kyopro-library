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
struct position{ int x, y; }; position mv[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; double euclidean(position first, position second){ return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y)); }
template<class itr> void array_output(itr start, itr goal){ for(auto i = start; i != goal; i++) cout << (i == start ? "" : " ") << (*i); cout << endl; }
template<class itr> void cins(itr first, itr last){ for(auto i = first; i != last; i++){ cin >> (*i); } }
template<class T> T gcd(T a, T b){ if(b) return gcd(b, a % b); else return a; }
template<class T> T lcm(T a, T b){ return a / gcd(a, b) * b; }
struct combination{ vector<lint> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2, mod); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } lint P(int n, int r){ if(r < 0 || n < r) return 0; return (fact[n] * inv[n - r] % mod); } lint C(int p, int q){ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };
template<class itr> bool next_sequence(itr first, itr last, int max_bound){ itr now = last; while(now != first){ now--; (*now)++; if((*now) == max_bound){ (*now) = 0; }else{ return true; } } return false; }
template<class itr, class itr2> bool next_sequence2(itr first, itr last, itr2 first2, itr2 last2){ itr now = last; itr2 now2 = last2; while(now != first){ now--, now2--; (*now)++; if((*now) == (*now2)){ (*now) = 0; }else{ return true; } } return false; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b){ if(b < a){ a = b; return 1; } return 0; }
inline int at(lint i, int j){ return (i >> j) & 1; }
random_device rnd;
bool is_in_board(lint y, lint x, lint H, lint W){ return (0 <= y && y < H && 0 <= x && x < W); }
lint inv2 = power(2, mod - 2, mod);

struct io_init {
   io_init() {
     cin.tie(nullptr); cout.tie(nullptr);
     std::ios::sync_with_stdio(false);
   }
} io_init;
