/*
 * Author:  heyuhhh
 * Created Time:  2020/4/14 19:45:33
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

ll n;
ll pow4[N], f[N];

void init() {
    pow4[0] = 1;
    for(int i = 1;; i++) {
        pow4[i] = pow4[i - 1] * 4;
        if(pow4[i] >= 1e18) break;
    }
}

void run() {
    cin >> n;
    ll now = (n + 2) / 3;
    int tot = 0;
    while(now > 1) {
        int high;
        ll res = 0;
        for(int i = 0;; i++) {
            res += pow4[i];
            if(res >= now) {
                res -= pow4[i], high = i;
                break;
            }
        }
        ll t = now - res - 1;
        int r = t % 4;
        f[++tot] = r;
        now = (now + 2) >> 2;
    }
    ll a = 1, b = 2, c = 3;
    for(int i = tot; i >= 1; i--) {
        a <<= 2, b <<= 2, c <<= 2;
        if(f[i] == 1) a += 1, b += 2, c += 3;
        if(f[i] == 2) a += 2, b += 3, c += 1;
        if(f[i] == 3) a += 3, b += 1, c += 2;
    }
    if(n % 3 == 0) cout << c << '\n';
    if(n % 3 == 1) cout << a << '\n';
    if(n % 3 == 2) cout << b << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    int T; cin >> T;
    while(T--) run();
    return 0;
}
