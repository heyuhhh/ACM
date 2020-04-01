/*
 * Author:  heyuhhh
 * Created Time:  2020/3/31 22:23:34
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
const int N = 2e5 + 5;

int n, k;
int cnt[N][26];
char s[N];

void run() {
    cin >> n >> k;
    cin >> (s + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 26; j++) {
            cnt[i][j] = 0;
        }
    }
    for(int i = 1; i <= k; i++) {
        for(int j = i; j <= n; j += k) {
            ++cnt[i][s[j] - 'a'];
        }   
    }
    int l = 1, r = k;
    int ans = 0;
    int d = n / k;
    while(l < r) {
        int res = INF;
        for(int i = 0; i < 26; i++) {
            res = min(res, 2 * d - cnt[l][i] - cnt[r][i]);
        }
        ans += res;
        ++l, --r;
    }
    if(l == r) {
        int res = INF;
        for(int i = 0; i < 26; i++) {
            res = min(res, d - cnt[l][i]);
        }   
        ans += res;
    }
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
