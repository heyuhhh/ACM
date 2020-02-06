/*
 * Author:  heyuhhh
 * Created Time:  2020/1/27 10:21:46
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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 2e5 + 5;

int n;
pii p[N];
int pref[N], lst[N];

void run(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i].fi >> p[i].se;   
    }
    sort(p + 1, p + n + 1);
    pref[1] = 1, lst[1] = p[1].se;
    for(int i = 2; i <= n; i++) {
        if(p[i].fi <= lst[i - 1]) {
            pref[i] = pref[i - 1];
            lst[i] = max(lst[i - 1], p[i].se);
        } else {
            pref[i] = pref[i - 1] + 1;
            lst[i] = p[i].se;
        }   
    }
    vector <pii> v;
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        int l = 0, r = sz(v), mid;
        while(l < r) {
            mid = (l + r) >> 1;
            if(v[mid].fi <= lst[i - 1]) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, pref[i - 1] + l);
        while(!v.empty() && v.back().fi <= p[i].se) {
            p[i].se = max(p[i].se, v.back().se);   
            v.pop_back();
        }
        v.push_back(p[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    lst[0] = -INF;
    int T; cin >> T;
    while(T--) run();
    return 0;
}
