/*
 * Author:  heyuhhh
 * Created Time:  2020/6/25 22:54:16
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

void run() {
    string s; cin >> s;
    int n = s.length();
    map <int, int> mp;
    int sum = 0, Min = INF;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') --sum;
        else ++sum;
        Min = min(Min, sum);
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i + 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (mp.find(-(i + 1)) != mp.end()) {
            ans += mp[-(i + 1)];
        } else break;
    }
    ans += n;
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
