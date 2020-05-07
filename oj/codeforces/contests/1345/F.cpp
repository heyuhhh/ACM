/*
 * Author:  heyuhhh
 * Created Time:  2020/5/7 21:30:21
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

ll n, k;
int a[N], b[N];

bool chk(ll A) {
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = a[i] + 1, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (a[i] - 3ll * mid * (mid - 1) - 1 >= A) l = mid + 1;
            else r = mid;
        }   
        b[i] = l - 1;
        s += b[i];
    }
    return s >= k;
}

void run() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll l = -8e18, r = 8e18, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (chk(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    ll A = l - 1, R = 0;
    chk(A);
    for (int i = 1; i <= n; i++) R += b[i];
    R -= k;
    for (int i = 1; i <= n && R; i++) {
        if (b[i] && a[i] - 3ll * b[i] * (b[i] - 1) - 1 == A) {
            --b[i], --R;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " \n"[i == n];   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
