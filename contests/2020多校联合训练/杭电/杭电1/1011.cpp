// Author : heyuhhh
// Created Time : 2020/07/22 18:51:06
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
    string s;
    cin >> s;
    int n = s.length();
    vector<bool> chk(n);
    vector<int> d(n);
    d[0] = 1;
    int i = 0;
    while (i < n) {
        int j = i + 1, k = i;
        int p = 0;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j]) {
                if (!chk[j]) {
                    d[j] = i + 1;
                }
                k = i;
                p = 0;
            } else {
                if (!chk[j]) {
                    d[j] = d[k] + j - k;
                }
                ++k;
            }
            chk[j] = true;
            ++j;
            ++p;
        }
        while (i <= k) {
            i += j - k;
        }
        if (i == j && j < n && !chk[j]) {
            chk[j] = true;
            d[j] = d[k] + j - k;
        }
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans = (1ll * ans * 1112 % MOD + d[i]) % MOD;
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