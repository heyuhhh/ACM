/*
 * Author:  heyuhhh
 * Created Time:  2020/5/12 20:51:42
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
const int N = 1e5 + 5, M = 2e5 + 5;

int n;
int a[N];
vector <int> v[M];

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        for (int j = 2; 1ll * j * j <= x; j++) {
            if (x % j == 0) {
                int cnt = 0;
                while (x % j == 0) {
                    x /= j;
                    ++cnt;
                }
                v[j].push_back(cnt);
            }
        }
        if (x > 1) {
            v[x].push_back(1);
        }
    }
    for (int i = 1; i < M; i++) {
        sort(all(v[i]));
    }
    ll ans = 1;
    for (int i = 1; i < M; i++) {
        if (sz(v[i]) <= n - 2) continue;
        if (sz(v[i]) == n - 1) {
            ans *= qpow(i, v[i][0]);
        } else {
            ans *= qpow(i, v[i][1]);
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
