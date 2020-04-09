/*
 * Author:  heyuhhh
 * Created Time:  2020/4/8 22:58:55
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
const int N = 2e5 + 5;

int n;
int a[N];
ll sum[N];

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    map <ll, int> mp;
    ll ans = 0;
    int rb = n + 1;
    for(int i = n; i >= 0; i--) {
        if(mp.find(sum[i]) != mp.end()) {
            int l = min(rb, mp[sum[i]]) - i - 1;
            ans += l;
            rb = min(rb, mp[sum[i]]);
        } else ans += rb - i - 1;
        //dbg(ans);
        mp[sum[i]] = i;
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
