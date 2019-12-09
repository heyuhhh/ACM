/*
 * Author:  heyuhhh
 * Created Time:  2019/10/30 21:16:50
 */
#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
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
typedef pair<ll, ll> pii;
//head
const int N = 2e5 + 5;

int n, m, w, h;
struct Node{
    ll x, y, z;
    bool operator < (const Node &A) const{
        return x < A.x;
    }
}a[N], b[N];

void run(){
    cin >> w >> h;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        ans += z;
        x = 1ll * x * h;
        y = 1ll * y * w;
        a[i] = Node{x + y, x - y, z};
    }
    for(int i = 1; i <= m; i++) { 
        ll x, y, z;
        cin >> x >> y >> z;
        x = 1ll * x * h;
        y = 1ll * y * w;
        b[i] = Node{x + y, x - y, z};
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    set <pii> S;
    for(int i = 1, j = 1; i <= m; i++) {
        while(j <= n && a[j].x <= b[i].x) {
            S.insert(MP(a[j].y, a[j].z));
            ++j;
        }
        ll c = b[i].z;
        while(c) {
            set <pii> :: iterator it = S.lower_bound(MP(b[i].y, 0));
            if(it == S.end()) break;
            pii now = *it;
            S.erase(it);
            ll tmp = min(c, now.se);
            now.se -= tmp;
            c -= tmp;
            ans -= tmp;
            if(now.se > 0) S.insert(now);
        }
        dbg(ans);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m) run();
	return 0;
}
