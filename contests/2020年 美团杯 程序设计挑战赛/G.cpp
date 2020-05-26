/*
 * Author:  heyuhhh
 * Created Time:  2020/5/19 16:11:42
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
const int N = 1e3 + 5;

ll qpow(ll a, ll b, ll p) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
//求模m的原根
int work(ll P, ll m) {   //P = phi(m)
    vector <int> div;
    ll x = P;
    for(int i = 2; 1ll * i * i <= x; i++) {
        if(x % i == 0) {
            div.push_back(i);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) div.push_back(x);
    for(int i = 2;; i++) {
        bool ok = true;
        for(auto x : div) {
            if(qpow(i, P / x, m) == 1) {
                ok = false; break;
            }
        }
        if(ok) return i;
    }
    return -1;
} 

void run() {
    int n;
    cin >> n;
    int g = work(n, n + 1);
    if (g == -1) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << qpow(g, i, n + 1) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
