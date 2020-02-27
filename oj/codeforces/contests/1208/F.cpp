/*
 * Author:  heyuhhh
 * Created Time:  2020/2/27 10:51:39
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
const int N = 2e6 + 5;

int n;
int a[N];
pii dp[N];

void add(int x, int id) {
    if(dp[x].fi == -1) {
        dp[x].fi = id;   
    } else if(dp[x].se == -1) {
        if(dp[x].fi == id) return;
        dp[x].se = id;   
        if(dp[x].fi < dp[x].se) swap(dp[x].fi, dp[x].se);
    } else if(dp[x].fi < id) {
        dp[x].se = dp[x].fi;
        dp[x].fi = id;   
    } else if(dp[x].se < id) {
        if(dp[x].fi == id) return;
        dp[x].se = id;
    }
}

void merge(int x1, int x2) {
    add(x1, dp[x2].fi);
    add(x1, dp[x2].se);
}

void run() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        add(a[i], i);
    }
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < N; j++) if(j >> i & 1) {
            merge(j ^ (1 << i), j);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n - 2; i++) {
        int lim = (1 << 21) - 1;
        int cur = a[i] ^ lim, res = 0;
        for(int j = 20; j >= 0; j--) if(cur >> j & 1) {
            if(dp[res ^ (1 << j)].se > i) {
                res ^= (1 << j);   
            }
        }
        ans = max(ans, res | a[i]);
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
