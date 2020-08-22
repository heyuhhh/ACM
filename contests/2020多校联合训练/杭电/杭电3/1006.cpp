// Author : heyuhhh
// Created Time : 2020/07/28 18:32:04
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
const int N = 20;

int a[N], tot;
ll C[N][N];

void init() {
    C[0][0] = 1;
    for (int i = 1; i < N; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}

ll calc(int s, vector<int>& cnt, int d, int lim, int t = tot) {
    if (lim) {
        if (s > t) return 0;
        ll res = 0;
        for (int i = 1; i < 10; i++) {
            ++cnt[i];
            res += calc(s + 1, cnt, d, 0);
            --cnt[i];
        }
        return res;
    }

    int now = cnt[d];
    int Max = 0;
    for (int i = 0; i < 10; i++) {
        if (i != d) Max = max(Max, cnt[i]);
    }

    int len = t - s + 1;
    if (len <= 0) {
        return Max < now;
    }

    ll res = 0;
    for (int x = max(now, Max + 1); x <= tot; x++) {
        vector<ll> f(len + 1);
        int t = x - now;
        if (t > len) continue;
        f[t] = C[len][t];
        for (int k = 0; k < 10; k++) {
            if (k == d) continue;
            for (int i = len; i > t; i--) {
                for (int j = t; j < i; j++) if (f[j] != 0) {
                    if (cnt[k] + i - j >= x) continue;
                    f[i] += C[len - j][i - j] * f[j];
                }
            }
        }
        res += f[len];
    }
    return res;
}

ll calc(ll x, int d) {
    tot = 0;
    ll t = x;
    while (t) {
        a[++tot] = t % 10;
        t /= 10;
    }
    reverse(a + 1, a + tot + 1);
    ll res = 0;
    for (int i = 1; i <= tot; i++) {
        vector<int> cnt(10);
        for (int j = 1; j < i; j++) {
            ++cnt[a[j]];
        }
        // 1 ~ i - 1匹配
        if (i == 1) {
            // 前导0
            for (int k = i + 1; k <= tot; k++) {
                res += calc(k, cnt, d, 1);
            }
        }
        int down = (i == 1 ? 1 : 0);
        int up = (i == tot ? 0 : 1);
        for (int j = down; j <= a[i] - up; j++) {
            ++cnt[j];
            res += calc(i + 1, cnt, d, 0);
            --cnt[j];
        }
    }
    return res;
}

void run() {
    ll l, r;
    int d;
    cin >> l >> r >> d;
    ll ans = calc(r, d) - calc(l - 1, d);
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