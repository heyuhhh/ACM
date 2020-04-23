/*
 * Author:  heyuhhh
 * Created Time:  2020/4/23 18:15:48
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
const int N = 20, M = 1e5 + 5;

ll f[1 << N], g[1 << N], h[1 << N];

char s[N][M];

void FWT_xor(ll *a, int n, int op) {
    for(int i = 1; i < n; i <<= 1)
        for(int p = i << 1, j = 0; j < n; j += p)
            for(int k = 0; k < i; k++) {
                ll X = a[j + k], Y = a[i + j + k];
                a[j + k] = X + Y; a[i + j + k] = X - Y;
                if(op == -1) a[j + k] = a[j + k] / 2, a[i + j + k] = a[i + j + k] / 2;
            }                
}

void run() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < 1 << n; i++) {
        int cnt = __builtin_popcount(i);
        g[i] = min(cnt, n - cnt);
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int j = 0; j < m; j++) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (s[i][j] == '1') x += (1 << i);
        }
        ++f[x];
    }
    int l = 1 << n;
    FWT_xor(f, l, 1), FWT_xor(g, l, 1);
    for (int i = 0; i < l; i++) h[i] = f[i] * g[i];
    FWT_xor(h, l, -1);
    ll ans = 1e18;
    for (int i = 0; i < l; i++) {
        ans = min(ans, h[i]);   
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
