/*
 * Author:  heyuhhh
 * Created Time:  2020/3/14 23:13:48
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
const int N = 64;

int cnt[N], need[N];

void run() {
    ll u, v; cin >> u >> v;
    for(int i = 0; i < N; i++) if(u >> i & 1) ++cnt[i];
    if(u > v) {
        cout << -1 << '\n';
        return;   
    }
    ll d = v - u;
    for(int i = N - 1; i >= 0; i--) if(d >> i & 1) {
        if(i) cnt[i - 1] += 2;
        else {
            cout << -1 << '\n';
            return;
        }
    }
    vector <ll> ans;
    while(1) {
        bool ok = false;
        for(int i = 0; i < N; i++) if(cnt[i]) ok = true;   
        if(!ok) break;
        ll res = 0;
        for(int i = 0; i < N; i++) if(cnt[i]) {
            res += 1ll << i;
            --cnt[i];   
        }
        ans.push_back(res);
    }
    cout << sz(ans) << '\n';
    for(auto it : ans) cout << it << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
