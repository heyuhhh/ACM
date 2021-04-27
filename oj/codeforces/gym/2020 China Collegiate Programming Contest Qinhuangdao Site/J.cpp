// Author : heyuhhh
// Created Time : 2020/10/26 15:50:45
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
//head
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
const int N = 3e5 + 5, MOD = 998244353;
const int base[2] = {2333, 5081}, mod[2] = {998244353, 1000000009};
int qpow(ll a, ll b, ll M) {
    ll res = 1;
    while(b) {
        if (b & 1) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
int fac[N], inv[N], hashPow[N][2];
void init() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = 1ll * fac[i - 1] * i % MOD;
    }
    inv[N - 1] = qpow(fac[N - 1], MOD - 2, MOD);
    for (int i = N - 2; i >= 0; i--) {
        inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    }
    hashPow[0][0] = hashPow[0][1] = 1;
    for (int j = 0; j < 2; j++) {
        for (int i = 1; i < N; i++) {
            hashPow[i][j] = 1ll * hashPow[i - 1][j] * base[j] % mod[j];
        }
    }
}

int n;
string s;

int p[N][2];

// 双模数hash，同时用链表维护hash值，支持插入hash值以及询问hash值对应的值
struct Hash {
    static const int MO = 19260817;
    int ka[N], kb[N], v[N], head[MO], next[N];
    int sta[N], top, sz;

    int getHash(int A, int B) {
        return (1ll * A * 2333 + B) % MO;
    }
    void init() {
        while (top) {
            head[sta[top--]] = 0;
        }
        sz = 0;
    }
    void add(int x, int y, int c) {
        int ha = getHash(x, y);
        for (int i = head[ha]; i; i = next[i]) {
            if (ka[i] == x && kb[i] == y) {
                v[i] += c;
                return;
            }
        }
        ka[++sz] = x, kb[sz] = y, v[sz] = c, next[sz] = head[ha], head[ha] = sz;
        sta[++top] = ha;
    }
    int query(int x, int y) {
        int ha = getHash(x, y);
        for (int i = head[ha]; i; i = next[i]) {
            if (ka[i] == x && kb[i] == y) {
                return v[i];
            }
        }
        return 0;
    }
}A, B; // A：子段hash值；B：集合hash值

int ans, res;
int pre[N], suf[N], cnt[N];
int tot;
int now[2];
// 得到区间hash值
int getHash(int l, int r, int t) {
    return (p[r][t] - 1ll * p[l - 1][t] * hashPow[r - l + 1][t] % mod[t] + mod[t]) % mod[t];
}
// 返回hash值，同时清空cnt数组
int getId(int x, int y) {
    int c = A.query(x, y);
    if (c != 0) return c;
    cnt[++tot] = 0;
    A.add(x, y, tot);
    return tot;
}
// 插入和删除，动态维护答案
void ins(int x) {
    res = 1ll * res * fac[cnt[x]] % MOD;
    ++cnt[x];
    res = 1ll * res * inv[cnt[x]] % MOD;
    now[0] = (now[0] + hashPow[x][0]) % mod[0];
    now[1] = (now[1] + hashPow[x][1]) % mod[1];
}
void del(int x) {
    res = 1ll * res * fac[cnt[x]] % MOD;
    --cnt[x];
    res = 1ll * res * inv[cnt[x]] % MOD;
    now[0] = (now[0] - hashPow[x][0] + mod[0]) % mod[0];
    now[1] = (now[1] - hashPow[x][1] + mod[1]) % mod[1];
}

void solve(int d) {
    A.init();
    tot = 0;
    int m = n / d;
    res = fac[m];
    // 预处理子段的pre，sum
    for (int i = 1; i <= m; i++) {
        int r1 = i * d, l1 = (i - 1) * d + 1;
        int l2 = n - i * d + 1, r2 = l2 + d - 1;
        pre[i] = getId(getHash(l1, r1, 0), getHash(l1, r1, 1));
        suf[m - i + 1] = getId(getHash(l2, r2, 0), getHash(l2, r2, 1));
    }
    now[0] = now[1] = 0;
    for (int i = 1; i <= m; i++) {
        ins(suf[i]);
    }
    B.init();
    for (int i = 0; i <= m; i++) {
        // 如果子段集合没有出现过就统计答案
        if (B.query(now[0], now[1]) == 0) {
            ans = (ans + res) % MOD;
            B.add(now[0], now[1], 1);
        }
        if (i < m) {
            del(suf[i + 1]);
            ins(pre[i + 1]);
        }
    }
}
int _;
void run() {
    ++_;
    cin >> s;
    n = s.length();
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            p[i][j] = (1ll * p[i - 1][j] * base[j] + s[i - 1]) % mod[j];
        }
    }
    ans = 0;
    for (int d = 1; d <= n; d++) solve(d);
    cout << "Case #" << _ << ": ";
    cout << ans << '\n';
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