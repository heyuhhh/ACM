// Author : heyuhhh
// Created Time : 2020/07/19 18:49:07
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
    int n, h, m, k;
    cin >> n >> h >> m >> k;
    vector<int> a(n);
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int H, M;
        cin >> H >> M;
        a[i] = M % (m / 2);
        v.push_back(a[i]);
        v.push_back(a[i] + m / 2);
    }
    sort(all(v));
    int s = 0;
    int Min = INF;
    int r = 0;
    dbg(v);
    for (int i = 0; i < sz(v); i++) {
        if (v[i] >= m / 2) break;
        while (i + 1 < sz(v) && v[i + 1] == v[i]) {
            ++i;
        }
        while (r < sz(v) && v[r] - v[i] < k) {
            ++r;
        }
        if (r - i - 1 < Min) {
            Min = r - i - 1;
            s = v[i];
        }
    }
    int t = (s + k) % (m / 2);
    cout << Min << ' ' << t << '\n';
    for (int i = 0; i < n; i++) {
        if ((a[i] > s && a[i] < s + k) || (a[i] + m / 2 > s && a[i] + m / 2 < s + k)) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
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