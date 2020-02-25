/*
 * Author:  heyuhhh
 * Created Time:  2020/2/24 9:56:55
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 5e5 + 5;

int n;
int a[N];
int f[N][21], g[N][21], lg[N];
ll sum[N];

ll query(int l, int r, int v) {
    return sum[r] - sum[l - 1] - 1ll * (r - l + 1) * v;
}

pii query(int l, int r) {
    int k = lg[r - l + 1];
    pii res;
    if(f[l][k] > f[r - (1 << k) + 1][k]) {
        res = MP(f[r - (1 << k) + 1][k], g[r - (1 << k) + 1][k]);   
    } else {
        res = MP(f[l][k], g[l][k]);   
    }
    return res;
}

ll solve(int l, int r) {
    if(l >= r) return 0;
    pii t = query(l, r);
    int v = t.fi, m = t.se;
    ll gl = query(l, m, v) + solve(m + 1, r), gr = query(m, r, v) + solve(l, m - 1);
    if(gl < gr) {
        for(int i = l; i <= m; i++) a[i] = v;
    } else {
        for(int i = m; i <= r; i++) a[i] = v;
    }
    return min(gl, gr);
}

void run(){
    cin >> n;
    lg[2] = 1;
    for(int i = 3; i <= n; i++) lg[i] = lg[i >> 1] + 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i][0] = a[i];
        g[i][0] = i;
        sum[i] = sum[i - 1] + a[i];
    }
    for(int j = 1; j <= 20; j++) {
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            int k = i + (1 << j) - 1;
            if(f[i][j - 1] > f[i + (1 << (j - 1))][j - 1]) {
                f[i][j] = f[i + (1 << (j - 1))][j - 1];
                g[i][j] = g[i + (1 << (j - 1))][j - 1];
            } else {
                f[i][j] = f[i][j - 1];
                g[i][j] = g[i][j - 1];
            }
        }   
    }
    ll ans = solve(1, n);
    for(int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();    
    return 0;
}
