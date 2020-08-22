// Author : heyuhhh
// Created Time : 2020/08/14 11:59:41
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
const int N = 1e5 + 5, MOD = 1e9 + 7;
void run() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m), s(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> s[i];
    }
    dbg(a);
    vector<int> p(30);
    for (int i = 0; i < k; i++) {
        for (int j = 29; j >= 0; j--) {
            if (s[i] >> j & 1) {
                if (!p[j]) {
                    p[j] = s[i];
                    break;
                }
                s[i] ^= p[j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 29; j >= 0; j--) if (a[i] >> j & 1) {
            a[i] ^= p[j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 29; j >= 0; j--) if (b[i] >> j & 1) {
            b[i] ^= p[j];
        }
    }
    int j;
    vector<int> nxt(m);
    nxt[0] = j = -1;
    for (int i = 1; i < m; i++) {
        while (j >= 0 && b[i] != b[j + 1]) j = nxt[j];
        if (b[i] == b[j + 1]) ++j;
        nxt[i] = j;
    }
    vector<int> pow2(n);
    pow2[0] = 1;
    for (int i = 1; i < n; i++) {
        pow2[i] = 1ll * pow2[i - 1] * 2 % MOD;
    }
    int ans = 0;
    j = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && (j == m - 1 || a[i] != b[j + 1])) j = nxt[j];
        if (a[i] == b[j + 1]) ++j;
        if (j == m - 1) {
            ans = (ans + pow2[i - m + 1]) % MOD;
        }
    }
    cout << ans << '\n';
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