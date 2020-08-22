// Author : heyuhhh
// Created Time : 2020/08/11 20:55:19
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
const int N = 1e6 + 5;

int f[N][21], g[N][21];

void run() {
    int t, a, c, m;
    cin >> t >> a >> c >> m;
    for (int i = 0; i < m; i++) {
        f[i][0] = (1ll * a * i % m + c) % m;
    }
    for (int j = 1; j <= 20; j++) {
        for (int i = 0; i < m; i++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }
    for (int i = 0; i < m; i++) {
        g[i][1] = (f[i][1] % 2);
    }
    for (int j = 2; j <= 20; j++) {
        for (int i = 0; i < m; i++) {
            g[i][j] = g[f[i][j - 1]][j - 1] + g[i][j - 1];
        }
    }
    auto query = [&] (int x, int t) {
        ll res = 0;
        for (int i = 20; i >= 0; i--) {
            if (t >> i & 1) {
                res += g[x][i];
                x = f[x][i];
            }
        }
        return res;
    };
    ll sum = 0, all = 1ll * (t + 1) * (t + 1);
    for (int i = 0; i <= t + t; i++) {
        if (i & 1) {
            int x = f[i][0];
            if (i >= t) {
                int d = i - t;
                sum += (x % 2 + query(x, t - d - 1));
            } else {
                sum += (x % 2 + query(x, i - 1));
            }
        } else {
            if (i >= t) {
                int d = i - t;
                sum += query(i, t - d);
            } else {
                sum += query(i, i);
            }
        }
    }
    sum = all - 2ll * sum;
    ll g = __gcd(sum, all);
    sum /= g, all /= g;
    cout << sum << "/" << all << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}