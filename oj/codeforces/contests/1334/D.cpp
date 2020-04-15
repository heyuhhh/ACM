/*
 * Author:  heyuhhh
 * Created Time:  2020/4/15 8:39:21
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
const int N = 1e5 + 5;

ll n, l, r;

ll f[N];
void init() {
    for(int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + 2 * (n - i);
    }
}

int calc(ll i) {
    if(i == f[n] + 1) return 1;
    int t = lower_bound(f + 1, f + n + 1, i) - f - 1;
    i -= f[t];
    if(i & 1) return t + 1;
    else return i / 2 + t + 1;
}

void run() {
    cin >> n >> l >> r;
    init();
    for(ll i = l; i <= r; i++) {
        cout << calc(i) << " \n"[i == r];   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
