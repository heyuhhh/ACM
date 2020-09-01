// Author : heyuhhh
// Created Time : 2020/07/17 11:14:42
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
const int N = 1e5 + 5;
void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p(n);
    iota(all(p), 0);
    sort(all(p), [&] (int i, int j) {
        return a[i] <= a[j];
    });

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[p[i]] = i;
    }

    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[i] > b[j]) {
                v[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        sort(all(v[i]), [&] (int x, int y) {
            return b[x] < b[y];
        });
    }
    vector<pii> ans;
    for (int i = n - 1; i >= 0; i--) {
        for (auto j : v[i]) {
            if (b[j] > b[i]) {
                swap(b[j], b[i]);
                ans.push_back(MP(j, i));
            } else {
                cout << -1 << '\n';
                return;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        if (b[i] < b[i - 1]) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << sz(ans) << '\n';
    for (auto it : ans) {
        cout << it.fi + 1 << ' ' << it.se + 1 << '\n';
    }
}
int main() {
#ifdef Local
   freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}