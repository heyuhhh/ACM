// Author : heyuhhh
// Created Time : 2020/07/17 14:18:49
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool ok = false;
    int inv = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) ok = true;
            if (a[i] > a[j]) ++inv;
        }
    }
    if (ok == false && (inv & 1)) {
        cout << -1 << '\n';
        return;
    }

    vector<int> b(n), p(n);
    iota(all(p), 0);
    sort(all(p), [&] (int i, int j) {
        return a[i] <= a[j];
    });
    inv = 0;
    for (int i = 0; i < n; i++) {
        b[p[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (b[i] > b[j]) ++inv;
        }
    }

    if (inv & 1) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] == a[j]) {
                    swap(b[i], b[j]);
                    goto out;
                }
            }
        } out:;
    }

    vector<int> ans;
    auto shift = [&] (int i) {
        int x = b[i], y = b[i + 1], z = b[i + 2];
        b[i + 1] = x;
        b[i + 2] = y;
        b[i] = z;
        ans.push_back(i);
    };

    for (int i = 0; i < n - 2; i++) {
        int Min = INF, pos;
        for (int j = i; j < n; j++) {
            if (b[j] < Min) {
                Min = b[j];
                pos = j;
            }
        }
        for (; pos - 2 >= i; pos -= 2) {
            shift(pos - 2);
        }
        if (pos == i + 1) {
            shift(i);
            shift(i);
        }
    }

    cout << sz(ans) << '\n';
    for (auto it : ans) {
        cout << it + 1 << ' ';
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
    int T; cin >> T; while(T--)
    run();
    return 0;
}