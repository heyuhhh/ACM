/*
 * Author:  heyuhhh
 * Created Time:  2020/3/6 10:54:19
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

int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;   
        if(res >= N || (a >= N && b)) return N;
    }
    return res;   
}

int n, k;
int a[N];
vector <pii> v[N];
vector <int> p[N];

void run() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; 
        int x = a[i], t = 1;
        for(int j = 2; j * j <= x; j++) {
            if(x % j == 0) {
                int c = 0;
                while(x % j == 0) x /= j, ++c;
                v[i].push_back(MP(j, c));
                t *= qpow(j, c % k);
            }   
        }
        if(x > 1) v[i].push_back(MP(x, 1)), t *= x;
        p[t].push_back(i);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll t = 1;
        bool f = true;
        for(auto it : v[i]) {
            int r = k - (it.se - 1) % k - 1;
            t = t * qpow(it.fi, r);
            if(t >= N) {f = false; break;}
        }   
        if(f) {
            int l = upper_bound(all(p[t]), i) - p[t].begin();
            ans += sz(p[t]) - l;
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
