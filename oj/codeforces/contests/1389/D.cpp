// Author : heyuhhh
// Created Time : 2020/08/24 11:29:30
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
    ll n, k;
    cin >> n >> k;
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (l1 > l2) swap(l1, l2), swap(r1, r2);
    
    k -= 1ll * n * max(0, min(r1, r2) - max(l1, l2));   
    if (k < 0) k = 0;

    int d = max(l2 - r1, 0);
    r1 += d;
    ll res = 0;
    int i = 1;
    do {
        res += d;
        int len = abs(r2 - r1);
        if (len >= k) {
            res += k;
            k = 0;
        } else {
            res += len;
            k -= len;
            len = abs(l2 - l1);
            if (len >= k) {
                res += k;
                k = 0;
            } else {
                res += len;
                k -= len;
            }
        }
    } while (++i <= n && k > d);
    
    res += 2 * k;
    cout << res << '\n';
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