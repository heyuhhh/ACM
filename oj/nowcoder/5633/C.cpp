/*
 * Author:  heyuhhh
 * Created Time:  2020/5/22 19:17:51
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
const int N = 2e5 + 5, MOD = 1e9 + 7;

void add(int &x, int y) {
    if (y >= MOD) y -= MOD;
    x += y;
    if (x >= MOD) x -= MOD;   
}

int n;
int a[N];
int suf[N], ssuf[N];

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        add(suf[i], suf[i + 1] + a[i]);
    }
    for (int i = n; i >= 1; i--) {
        add(ssuf[i], ssuf[i + 1] + suf[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int res = 1ll * i * a[i] % MOD * (1ll * (n - i + 1) * suf[i] % MOD - ssuf[i + 1] + MOD) % MOD;
        add(ans, res);
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
