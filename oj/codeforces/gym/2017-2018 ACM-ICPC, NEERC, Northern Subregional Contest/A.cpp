/*
 * Author:  heyuhhh
 * Created Time:  2020/6/11 13:13:46
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
const int N = 1e6 + 5;

const int mp[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int val[] = {-1, -1, 1, 7, 4, 5, 9, 8, -1, -1, -1};
int n;
int dp[N];

void run() {
    freopen("auxiliary.in", "r", stdin);
    freopen("auxiliary.out", "w", stdout);
    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 10; j++) if (val[j] != -1 && i >= j && dp[i - j] != -1) {
            dp[i] = max(dp[i], dp[i - j] + val[j]);
        }   
    }
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
