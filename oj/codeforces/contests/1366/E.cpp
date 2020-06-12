/*
 * Author:  heyuhhh
 * Created Time:  2020/6/12 0:19:36
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#include <functional>
#include <numeric>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << std::endl; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 2e5 + 5, MOD = 998244353;

int n, m;
int a[N], b[N];

int f[N][21], g[N][21];
void Get_st(){
    for(int j=1;j<=20;j++)
        for(int i=1;i<=n;i++)
            if(i+(1<<(j-1))<=n) {
                if (f[i][j-1] < f[i+(1<<(j-1))][j-1]) {
                    f[i][j] = f[i][j-1];
                    g[i][j] = g[i][j - 1];
                } else if (f[i][j-1] >= f[i+(1<<(j-1))][j-1]) {
                    f[i][j] = f[i+(1<<(j-1))][j-1];
                    g[i][j] = g[i+(1<<(j-1))][j-1];
                }
            }  
}
pii Get_min(int l,int r){
    if (l > r) {
        return MP(INF, 0);
    }
    int k=0;
    while(1<<(k+1)<=r-l+1) k++;
    if (f[l][k] < f[r-(1<<k)+1][k]) return MP(f[l][k], g[l][k]);
    return MP(f[r-(1<<k)+1][k], g[r-(1<<k)+1][k]);
} 

void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        f[i][0] = a[i];
        g[i][0] = i;
    }
    Get_st();
    int l = 1;
    vector <pair<pii, int>> v;
    for (int i = 1; i < m; i++) {
        int L = l, R = n + 1, mid;
        while (L < R) {
            mid = (L + R) >> 1;
            if (Get_min(l, mid).fi == b[i] && Get_min(mid + 1, n).fi >= b[i + 1]) {
                R = mid;
            } else {
                L = mid + 1;
            }
        }
        int r = L;
        v.push_back(MP(MP(l, r), Get_min(l, r).se));
        l = r + 1;
        if (l > n) {
            cout << 0 << '\n';
            return;
        }
    }
    v.push_back(MP(MP(l, n), Get_min(l, n).se));
    for (int i = 0; i < sz(v); i++) {
        if (Get_min(v[i].fi.fi, v[i].fi.se).fi != b[i + 1]) {
            cout << 0 << '\n';
            return;
        }
    }
    int ans = 1;
    for (int i = 1; i < sz(v); i++) {
        int x = v[i].se - v[i - 1].fi.se;
        ans = 1ll * ans * x % MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
