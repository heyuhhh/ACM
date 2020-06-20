/*
 * Author:  heyuhhh
 * Created Time:  2020/6/18 16:22:01
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
const int N = 1e5 + 5;
int s[N];
int d[N];
void run() {
    int n,m,p; 
    cin >> n >> m >> p;
    for(int i=1; i<=n; i++) {
        cin >> s[i];
    }
    ll sum = 0;
    for(int i=0; i<p; i++) {
        int a,b; cin >> a >> b;
        d[i] = ((s[a] - b)%m + m) % m;
        sum += d[i];
    }
    ll ans = sum;
    sort(d,d+p);
    for(int i=0; i<p;) {
        int now=i;
        for(i++;i<p && d[i]==d[now]; i++);
        int cnt=i-now;
        ll res = sum - 1ll * p * d[now] + 1ll * now * m;
        ans = min(ans, res);
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
