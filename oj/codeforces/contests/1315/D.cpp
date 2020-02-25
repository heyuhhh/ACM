/*
 * Author:  heyuhhh
 * Created Time:  2020/2/25 20:12:14
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

int n;
pii a[N];

void run(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].fi;
    for(int i = 1; i <= n; i++) cin >> a[i].se;
    sort(a + 1, a + n + 1, [&](pii A, pii B) {
        return A.fi < B.fi;
    });
    multiset <int> s;
    ll ans = 0, tot = 0;
    for(int i = 1, j; i <= n; i = j) {
        j = i;
        while(j <= n && a[i].fi == a[j].fi) ++j;
        for(int k = i; k < j; k++) {
            tot += a[k].se;
            s.insert(a[k].se);
        }
        int now = a[i].fi;
        while(!s.empty() && now != a[j].fi) {
            auto it = s.end(); --it;
            tot -= *it;
            s.erase(it); 
            ++now;
            ans += tot;
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
