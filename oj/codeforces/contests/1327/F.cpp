/*
 * Author:  heyuhhh
 * Created Time:  2020/3/24 17:50:08
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
const int N = 5e5 + 5, MOD = 998244353 ;

int n, k, m;
int l[N], r[N], x[N];
int pre[N], cnt[N];
int dp[N];

int solve(int bit) {
    dp[0] = 1;
    memset(pre, 0, sizeof(pre));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= m; i++) {
        if(x[i] >> bit & 1) ++cnt[l[i]], --cnt[r[i] + 1];   
        else pre[r[i]] = max(pre[r[i]], l[i]);
    }
    int s = 1, tail = 0;
    for(int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
        if(cnt[i]) dp[i] = 0;
        else dp[i] = s;
        while(tail < pre[i]) {
            s -= dp[tail++];
            if(s < 0) s += MOD;    
        }
        s += dp[i]; s %= MOD;
    }
    return s;
}

void run() {
    cin >> n >> k >> m;
    for(int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i] >> x[i];
    }
    int ans = 1;
    for(int bit = 0; bit < k; bit++) {
        ans = 1ll * ans * solve(bit) % MOD;
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
