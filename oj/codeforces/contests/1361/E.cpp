/*
 * Author:  heyuhhh
 * Created Time:  2020/6/5 8:18:48
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
const int N = 1e5 + 5, MOD = 1e9 + 7;

int qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void run() {
    int n, p; cin >> n >> p;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (p == 1) {
        if (n & 1) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
        return;   
    }
    sort(all(a));
    vector <int> l, r;
    while (sz(a)) {
        r.push_back(a.back());
        a.pop_back();
        ll A = 1;
        int x = r.back();
        for (int i = sz(a) - 1; i >= 0; i--) {
            l.push_back(a[i]);
            int d = x - a[i];
            x = a[i];
            a.pop_back();
            while (d && A < n) {
                A *= p;
                --d;
            }
            if (d == 0 && --A == 0) {
                break;
            }
        }
    }
    int ans = 0;
    for (auto it : l) {
        ans = (ans + MOD - qpow(p, it)) % MOD;
    }
    for (auto it : r) {
        ans = (ans + qpow(p, it)) % MOD;
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
