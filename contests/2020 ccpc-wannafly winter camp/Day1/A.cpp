/*
 * Author:  heyuhhh
 * Created Time:  2020/1/13 7:27:08
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
const int N = 5e3 + 5, MOD = 998244353;

struct seg {
    int l, r;
    bool operator < (const seg &A) const {
        return 1.0 * (r + l) / 2 < 1.0 * (A.r + A.l) / 2;   
    }
}a[N];
int n;

int inv[N];

ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return ans;   
}

int sum(int a, int b) {
    return 1ll * (a + b) * (b - a + 1) / 2 % MOD;   
}

void run(){
    for(int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
         inv[i] = qpow(a[i].r - a[i].l + 1, MOD - 2);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(a[j].l >= a[i].r) continue;
            if(a[j].l >= a[i].l) {
                int res = sum(1, min(a[j].r, a[i].r) - a[j].l);
                if(a[j].r < a[i].r) {
                    res = (res + 1ll * (a[i].r - a[j].r) * (a[j].r - a[j].l + 1) % MOD) % MOD;
                }
                res = 1ll * res * inv[i] % MOD * inv[j] % MOD;
                ans = (ans + res) % MOD;
            } else {
                int res = sum(1, a[i].r - a[i].l);
                res = (res + 1ll * (a[i].l - a[j].l) * (a[i].r - a[i].l + 1) % MOD) % MOD;
                res = 1ll * res * inv[i] % MOD * inv[j] % MOD;
                ans = (ans + res) % MOD;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
