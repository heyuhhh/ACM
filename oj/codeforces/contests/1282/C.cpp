/*
 * Author:  heyuhhh
 * Created Time:  2020/1/31 10:27:51
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
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 2e5 + 5;

int n, t, a, b;
pii d[N];
int pre[N];

void run(){
    cin >> n >> t >> a >> b;
    for(int i = 1; i <= n; i++) {
        cin >> d[i].se;
    }
    for(int i = 1; i <= n; i++) {
        cin >> d[i].fi;   
    }
    sort(d + 1, d + n + 1);
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (d[i].se == 1);   
    }
    int ans = 0;
    int tota = n - pre[n], totb = pre[n];
    d[n + 1].fi = t + 1;
    for(int i = 0; i <= n; i++) {
        ll cost = 1ll * pre[i] * b + 1ll * (i - pre[i]) * a;
        ll r = d[i + 1].fi - cost - 1;
        int ra = tota - i + pre[i], rb = totb - pre[i];
        if(r >= 0) {
            if(a < b) {
                int ta = min(r / a, (ll)ra);
                r -= 1ll * ta * a;
                int tb = min(r / b, (ll)rb);
                ans = max(ans, i + ta + tb);
            } else {
                int tb = min(r / b, (ll)rb);
                r -= 1ll * tb * b;
                int ta = min(r / a, (ll)ra);
                ans = max(ans, i + ta + tb);
            }   
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
