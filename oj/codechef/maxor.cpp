/*
 * Author:  heyuhhh
 * Created Time:  2020/4/27 20:29:14
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
const int N = 20;

int n;
int a[1 << N], f[1 << N], cnt[1 << N];

void run() {
    cin >> n;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];   
        ++f[a[i]];
        cnt[a[i]] = 1;
    }
    for (int j = 0; j < N; j++) 
    for (int i = 0; i < 1 << N; i++)
        if (i >> j & 1) f[i] += f[i ^ (1 << j)];
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += f[a[i]] - cnt[a[i]];
        ++cnt[a[i]];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
