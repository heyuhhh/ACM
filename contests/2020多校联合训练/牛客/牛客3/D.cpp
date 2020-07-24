// Author : heyuhhh
// Created Time : 2020/07/19 09:35:17
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
const int N = 1e5 + 5;
void run() {
    int n, m;
    cin >> n >> m;
    
    int a, b;
    int Min = INF;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (i * j >= n && (i - 1) * j < n && i * (j - 1) < n) {
                if (2 * (i + j) < Min) {
                    Min = 2 * (i + j);
                    a = i, b = j;
                }
                if (2 * (i + j) == m) {
                    a = i, b = j;
                    goto nxt;
                }
            }
        }
    } nxt:;
    if (m & 1 || m > 4 * n || m < 2 * (a + b)) {
        cout << "No" << '\n';
        return;
    }
    dbg(a, b);
    vector<pii> ans;
    int tot = 2 * (a + b);
    int r = n;
    for (int i = 1; i <= a && r; i++) {
        for (int j = 1; j <= b && r; j++, --r) {
            ans.push_back(MP(i, j));
        }
    }
    vector<pii> res;
    int x = 1000000, y = 100000000;
    while (sz(ans) > 1 && m - tot >= 4) {
        pii now = ans.back();
        ans.pop_back();
        if (now.se == 1 || now.fi == 1) {
            tot += 2;
        } else {
            tot += 4;
        }
        res.push_back(MP(x, y));
        x += 2;
    }
    assert(m - tot <= 2);
    if (m - tot >= 2) {
        pii now = ans.back();
        ans.pop_back();
        if (now.fi == 1 || now.se == 1) {
            res.push_back(MP(x, y));
        } else {
            res.push_back(MP(now.fi - 1, b + 1));
        }
    }
    cout << "Yes" << '\n';
    for (auto it : res) {
        cout << it.fi << ' ' << it.se << '\n';
    }
    for (auto it : ans) {
        cout << it.fi << ' ' << it.se << '\n';
    }
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