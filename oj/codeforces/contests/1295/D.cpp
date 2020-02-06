/*
 * Author:  heyuhhh
 * Created Time:  2020/1/29 23:40:43
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
 
ll a, m;
 
ll get(ll n, ll p) {
    return n / p;
}
 
ll get(ll l, ll r, ll p) {
    return get(r, p) - get(l - 1, p);   
}
 
vector <ll> divs;
ll ans, l, r;

void solve(int cur, ll now, int cnt) {
    if(now > r) return;
    if(cur == sz(divs)) {
        if(now == 1) return;
        if(cnt & 1) ans -= get(l, r, now);
        else ans += get(l, r, now);
        return;
    }  
    solve(cur + 1, now, cnt);
    solve(cur + 1, now * divs[cur], cnt ^ 1);
}

void run(){
    divs.clear();
    cin >> a >> m;
    ll d = __gcd(a, m);
    a /= d, m /= d;
    l = a, r = a + m - 1;
    ans = m;
    for(ll i = 2; i * i <= m; i++) {
        if(m % i == 0) {
            divs.push_back(i);
            while(m % i == 0) m /= i;
        }
    }
    if(m > 1) divs.push_back(m);
    solve(0, 1, 0);
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
