/*
 * Author:  heyuhhh
 * Created Time:  2020/4/10 23:00:09
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
const int N = 6e5 + 5;

int n;
ll a[N], b[N];

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        a[i + n] = a[i], b[i + n] = b[i];
    }
    ll ans = 0;
    int rb = 1;
    vector <pii> v;
    bool f = false;
    for(int i = 1; i <= n; i++) {
        int j = rb + 1;
        while(j <= i + n && b[j - 1] >= a[j]) ++j;
        rb = j - 1;
        //环
        if(rb == i + n) {
            cout << *min_element(a + 1, a + n + 1) << '\n';
            return;
        }
        //len = n
        if(rb == i + n - 1) {
            ll Min = *min_element(a + i + 1, a + rb);
            if(Min < b[rb]) {
                cout << a[i] + Min - b[rb] << '\n';
            } else {
                cout << a[i] << '\n';
            }
            return;
        }
        v.push_back(MP(i, rb));
        if(i <= n && rb >= 1) f = true;
    }
    vector <pii> seg;
    int last = -1;
    if(f) {
        for(auto it : v) {
            if(it.fi <= n && it.se >= 1) f = false;
            if(!f && it.fi > last) seg.push_back(it), last = it.se;
        }   
    } else {
        for(auto it : v) {
            if(it.fi > last) seg.push_back(it), last = it.se;
            if(it.se == n) break;  
        }          
    }
    vector <ll> vv;
    for(auto it : seg) {
        ans += a[it.fi] - b[it.se];
        vv.push_back(b[it.se]);
    }
    sort(all(vv));
    ans += vv[0];
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
