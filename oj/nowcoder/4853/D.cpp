/*
 * Author:  heyuhhh
 * Created Time:  2020/3/27 19:41:46
 */
#include <iostream>
#include <algorithm>
#include <cstring>
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
  void err() { std::cout << '\n'; }
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
#define LL long long
int a, b, c;
ll k;

void exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1, y = 0;
        return ;
    }
    exgcd(b,a%b,x,y);
    ll z = x ;
    x = y;
    y = z - y * (a / b);
} 

ll calc(ll a, ll b, ll c) {
    ll x, y;
    ll g = __gcd(a, b);
    if(c % g != 0) return -1;
    a /= g, b /= g, c /= g;
    exgcd(a, b, x, y);
    x *= c;
    x = (x % b + b) % b;
    return x;
}

void run() {
    cin >> a >> b >> c >> k;
    for(int i = 0;; i++) {
        ll d = k - 1ll * i * c;
        ll x, y;
        x = calc(a, b, d);
        if(x >= 0 && (d - 1ll * x * a) % b == 0) {
            y = (d - x * a) / b;
            if(y >= 0) {
                cout << x << ' ' << y << ' ' << i << '\n';
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
