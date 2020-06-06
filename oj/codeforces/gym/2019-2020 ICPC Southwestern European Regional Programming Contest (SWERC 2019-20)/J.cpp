/*
 * Author:  heyuhhh
 * Created Time:  2020/5/21 15:22:22
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
const int N = 2e6 + 5, MOD = 1e9 + 7;

int fac[N], inv[N], INV[N];
int qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;   
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int cat(int n) {
    return 1ll * C(2 * n, n) * INV[n + 1] % MOD;
}
int f[N][21];
int n;
void Get_st(){
    for(int j=1;j<=20;j++)
        for(int i=1;i<=n;i++)
            if(i+(1<<(j-1))<=n) f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int Get_min(int l,int r){
    if (l > r) return INF;
    int k=0;
    while(1<<(k+1)<=r-l+1) k++;
    return min(f[l][k],f[r-(1<<k)+1][k]);
} 
vector <int> p[N];

void run() {
    cin >> n;
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    for (int i = N - 1; i >= 0; i--) INV[i] = qpow(i, MOD - 2);
    memset(f, INF, sizeof(f));
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        f[i][0] = x;
        p[x].push_back(i);
    }
    Get_st();
    int ans = 1;
    for (int i = N - 1; i >= 0; i--) if (sz(p[i])) {
        int cnt = 1;
        for (int j = 1; j < sz(p[i]); j++) {
            int L = p[i][j - 1], R = p[i][j];
            if (Get_min(L + 1, R - 1) > i) {
                ++cnt;
            } else {
                if (cnt > 1) {
                    ans = 1ll * ans * cat(cnt) % MOD;
                }
                cnt = 1;
            }
        }
        if (cnt > 1) {
            ans = 1ll * ans * cat(cnt) % MOD;
        }
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
