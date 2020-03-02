#include <bits/stdc++.h>
#define fi first
#define se second
#define endl "\n"
using namespace std;
using db = double;
using ll = long long;
using ull = unsigned long long;
using pII = pair <int, int>;
using pLL = pair <ll, ll>;
constexpr int mod = 1e9 + 7;
template <class T1, class T2> inline void chadd(T1 &x, T2 y) { x += y; while (x >= mod) x -= mod; while (x < 0) x += mod; }
template <class T1, class T2> inline void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template <class T1, class T2> inline void chmin(T1 &x, T2 y) { if (x > y) x = y; }
inline int rd() { int x; cin >> x; return x; }
template <class T> inline void rd(T &x) { cin >> x; }
template <class T> inline void rd(vector <T> &vec) { for (auto &it : vec) cin >> it; } 
#define dbg(x...) do { cout << "\033[32;1m" << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template <class T, class... Ts> void err(const T& arg, const Ts&... args) { cout << arg << ' '; err(args...); }
template <template<typename...> class T, typename t, typename... A>
void err(const T <t> &arg, const A&... args) { for (auto &v : arg) cout << v << ' '; err(args...); }
void ptt() { cout << endl; }
template <class T, class... Ts> void ptt(const T& arg, const Ts&... args) { cout << ' ' << arg; ptt(args...); }
template <class T, class... Ts> void pt(const T& arg, const Ts&... args) { cout << arg; ptt(args...); }
void pt() {}
template <template<typename...> class T, typename t, typename... A>
void pt(const T <t> &arg, const A&... args) { for (int i = 0, sze = arg.size(); i < sze; ++i) cout << arg[i] << " \n"[i == sze - 1]; pt(args...); }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll qpow(ll base, ll n) { ll res = 1; while (n) { if (n & 1) res = res * base % mod; base = base * base % mod; n >>= 1; } return res; }
//head
constexpr int N = 1e3 + 10;
int n, K; ll f[2][N * N], g[N], h[N], fac[N], inv[N], val[N * N];
constexpr int p = 1e9 + 7;
struct Lagrange {
    static const int SIZE = 1e3 + 10;
    ll f[SIZE], fac[SIZE], inv[SIZE], pre[SIZE], suf[SIZE];
    int n;
    void add(ll &x, ll y) {
        x += y;
        if (x >= p) x -= p;
    }
    void init(int _n, ll *_f) {
        n = _n;
        fac[0] = 1;
        for (int i = 1; i < SIZE; ++i) fac[i] = fac[i - 1] * i % p;
        inv[SIZE - 1] = qpow(fac[SIZE - 1], p - 2);
        for (int i = SIZE - 1; i >= 1; --i) inv[i - 1] = inv[i] * i % p;
        for (int i = 0; i <= n; ++i)
            f[i] = _f[i];
    }
    ll cal(ll x) {
        if (x <= n) return f[x];
        pre[0] = x % p;
        for (int i = 1; i <= n; ++i) pre[i] = pre[i - 1] * ((x - i) % p) % p;
        suf[n] = (x - n) % p;
        for (int i = n - 1; i >= 0; --i) suf[i] = suf[i + 1] * ((x - i) % p) % p;
        ll res = 0;
        for (int i = 0; i <= n; ++i) {
            ll tmp = f[i] * inv[n - i] % p * inv[i] % p;
            if (i) tmp = tmp * pre[i - 1] % p;
            if (i < n) tmp = tmp * suf[i + 1] % p;
            if ((n - i) & 1) tmp = p - tmp;
            add(res, tmp);
        }
        return res;
    }
}lagrange;
 
void run() {
    int m = K * 6; 
    for (int i = 0; i <= m * m; ++i) val[i] = qpow(i, K);
    f[1][0] = 1;
    chadd(g[1], 1ll * f[1][0] * val[0] % mod);
    int limit = 0;
    for (int i = 2; i <= m; ++i) {
        int p = i & 1;
        limit += i - 1;
        for (int j = 0; j <= limit; ++j) {
            f[p][j] = 0;
            if (j) chadd(f[p ^ 1][j], f[p ^ 1][j - 1]);
            chadd(f[p][j], f[p ^ 1][j]);
            if (j - i >= 0) chadd(f[p][j], mod - f[p ^ 1][j - i]);
            chadd(g[i], f[p][j] * val[j] % mod);
        }
    }
    for(int i = 1; i <= 4 * K; i++) cout << g[i] << '\n';
    if (n <= m) {
        pt(g[n]);
    } else {
        for (int i = K * 2; i <= m; ++i) {
            h[i - K * 2] = g[i] * inv[i - K * 2] % mod;
        }
        lagrange.init(m - K * 2, h);
        ll res = lagrange.cal(n - K * 2);
        for (int i = 2; i <= n - K * 2; ++i)
            res = res * i % mod;
        pt(res);
    }
}
 
int main() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % mod;
    inv[N - 1] = qpow(fac[N - 1], mod - 2);
    for (int i = N - 1; i >= 1; --i) inv[i - 1] = inv[i] * i % mod;
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    while (cin >> n >> K) run();
    return 0;
}
