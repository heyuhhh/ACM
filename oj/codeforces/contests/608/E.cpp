/*
 * Author:  heyuhhh
 * Created Time:  2019/12/15 17:45:31
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
const int N = 1e5 + 5;

ll n, k;

ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a;
        a = a * a; 
        b >>= 1;   
    }
    return ans;   
}

bool chk(ll x) {
    ll cnt = 0;
    
        ll now = x, tmp = 1 + (x % 2 == 0);
        int k = 0;
        for(int i = 0; i < 61; i++) {
            if(now > n) {
                k = i - 1; now /= 2; tmp /= 2; cnt -= tmp;
                break;   
            }
            cnt += tmp;
            now *= 2; tmp *= 2; 
        }
        ll d = min(n - now + 1, tmp);
        cnt += d;
        dbg(x, cnt);
    return cnt >= k;
}

void run(){
    ll l = 2, r = n + 1, mid;
    ll ans = 1;
    while(l < r) {
        mid = (l + r) >> 1;
        if(mid & 1) ++mid;
        if(mid >= r) mid -= 2;
        if(mid < l) break;
        if(chk(mid)) {
            ans = mid;
            l = mid + 2;
        } else r = mid - 1;
    }
    l = 1, r = n + 1;
    while(l < r) {
        mid = (l + r) >> 1;
        if(mid % 2 == 0) ++mid;
        if(mid >= r) mid -= 2;
        if(mid < l) break;
        if(chk(mid)) {
            ans = max(ans, mid);
            l = mid + 2;
        } else r = mid - 1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> k) run();
    return 0;
}
