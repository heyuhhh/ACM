// Author : heyuhhh
// Created Time : 2020/08/06 10:41:24
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void err(int x) {cerr << x;}
void err(long long x) {cerr << x;}
void err(double x) {cerr << x;}
void err(char x) {cerr << '"' << x << '"';}
void err(const string &x) {cerr << '"' << x << '"';}
void _print() {cerr << "]\n";}
template<typename T, typename V>
  void err(const pair<T, V> &x) {cerr << '{'; err(x.first); cerr << ','; err(x.second); cerr << '}';}
template<typename T>
  void err(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), err(i); cerr << "}";}
template <typename T, typename... V>
  void _print(T t, V... v) {err(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef Local
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
//head
const int N = 1e6 + 5, MOD = 1e9 + 7;

int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return res;   
}
int fac[N], inv[N];
void init() {
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
}

int C(int n, int m) {
    if (n < m || n < 0 || m < 0) return 0;
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

void add(int& x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int f[N], sz[N];
int n, m;
int ans[N];

void run() {
    cin >> n >> m;
    for (int i = 2; i <= n; i++) {
        cin >> f[i];
    }
    int p = (m - 1) / 2;
    ans[1] = C(n - 1, m - 1);
    for (int i = 2; i <= n; i++) {
        int t = 1ll * C(i - 2, p - 1) * C(n - i, m - 1 - p) % MOD;
        ans[i] = (ans[i - 1] - t + MOD) % MOD;
    }
    if (p == 0) {
        for (int i = 1; i <= n; i++) {
            ans[i] = 0;
        }
    }
    for (int i = 1; 2 * i <= n; i++) {
        ans[i] = 1ll * ans[i] * i % MOD + 1ll * ans[n - i] * (n - i) % MOD;
        ans[i] %= MOD;
    }
    for (int i = 1; i <= n; i++) {
        sz[i] = 1;
    }
    for (int i = n; i > 1; i--) {
        sz[f[i]] += sz[i];
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int s = sz[i];
        if (s < n) {
            add(res, ans[min(s, n - s)]);
            if (m % 2 == 0) {
                int tmp = 1ll * (m / 2) * C(s, m / 2) % MOD * C(n - s, m / 2) % MOD;
                add(res ,tmp);
            }
        }
    }
    cout << res << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    int T; cin >> T; while(T--)
    run();
    return 0;
}