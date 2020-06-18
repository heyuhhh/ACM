/*
 * Author:  heyuhhh
 * Created Time:  2020/6/16 22:41:13
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
    int n, k; cin >> n >> k;
    vector <int> v;
    for (int i = 1; i <= k; i++) {
        if (k % i == 0) {
            v.push_back(i);
        }
    }
    string s; cin >> s;
    vector <int> cnt(26);
    for (int i = 0; i < n; i++) {
        ++cnt[s[i] - 'a'];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (auto it : v) {
            if (it % i == 0) {
                ans = max(ans, i);
            }
            if(i % it == 0) { 
                int d = i / it;
                int c = 0;
                for (int j = 0; j < 26; j++) {
                    c += cnt[j] / d;
                }
                if (c >= it) {
                    ans = max(ans, i);
                }
            }
        }
    }
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
