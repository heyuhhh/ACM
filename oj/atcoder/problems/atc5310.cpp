/*
 * Author:  heyuhhh
 * Created Time:  2020/5/12 16:31:40
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
const int N = 1e5 + 5, MOD = 1e9 + 7;

int mu[N], sum[N], p[N];
bool chk[N];
void init() {
    mu[1] = 1;
    int cnt = 0;
    for(int i = 2; i < N; i++) {
        if(!chk[i]) p[++cnt] = i, mu[i] = -1;
        for(int j = 1; j <= cnt && i * p[j] < N; j++) {
            chk[i * p[j]] = 1;
            if(i % p[j] == 0) {
                mu[i * p[j]] = 0; 
                break;
            }
            mu[i * p[j]] = -mu[i];
        }
    }
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + mu[i];
    }
}

int n, k;

int qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int f(int k) {
    int ans = 0;
    for (int l = 1, r; l <= k; l = r + 1) {
        r = min(k, k / (k / l));
        ans = ((ll)ans + 1ll * (sum[r] - sum[l - 1]) * qpow(k / l, n) % MOD + MOD) % MOD;
    }
    return ans;
}

void run() {
    cin >> n >> k;
    int ans = 0;
    for (int l = 1, r; l <= k; l = r + 1) {
        r = min(k, k / (k / l));
        ans = (ans + (1ll * (l + r) * (r - l + 1) / 2) % MOD * f(k / l) % MOD) % MOD;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    run();
    return 0;
}
