/*
 * Author:  heyuhhh
 * Created Time:  2020/2/21 16:11:43
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
const int N = 1e5 + 5, MOD = 1e9 + 7, inv2 = (MOD + 1) / 2;

struct Bit {
    int c[N];
    void init() {
        memset(c, 0, sizeof(c));
    }   
    int lowbit(int x) {return x & (-x);}
    void add(int x, int v) {
        for(; x < N; x += lowbit(x)) {
            c[x] = (c[x] + v) % MOD;
        }
    }
    int query(int x) {
        int res = 0;
        for(; x; x -= lowbit(x)) {
            res = (res + c[x]) % MOD;
        }
        return res;   
    }
    int query(int l, int r) {
        if(l > r) return 0;
        return (query(r) - query(l - 1) + MOD) % MOD;
    }
}bit, bit2;

int n, ans[N];
int a[N], b[N];
int l[N], r[N];
int f[N << 1], g[N << 1];

void run(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], b[a[i]] = i;
    for(int i = 1; i <= n; i++) {
        bit.add(b[i], f[n + b[i] - 1]);
        bit2.add(b[i], (n - b[i] - 1 < 0 ? inv2 : f[n - b[i] - 1]));
        if(i + 2 <= n) {
            int t = bit.query(1, b[i + 2] - 1), t2 = bit2.query(b[i + 2] + 1, n);
            l[i + 2] = (1ll * t * g[b[i + 2]] % MOD + 1ll * t2 * f[b[i + 2]] % MOD) % MOD;
        }
    }
    bit.init(); bit2.init();
    for(int i = n; i >= 1; i--) {
        bit.add(b[i], f[n + b[i] - 1]);
        bit2.add(b[i], (n - b[i] - 1 < 0 ? inv2 : f[n - b[i] - 1]));
        if(i - 2 >= 1) {
            int t = bit.query(1, b[i - 2] - 1), t2 = bit2.query(b[i - 2] + 1, n);
            r[i - 2] = (1ll * t * g[b[i - 2]] % MOD + 1ll * t2 * f[b[i - 2]] % MOD) % MOD;
        }   
    }
    for(int i = 2; i < n; i++) {
        ans[i] = ((ans[i - 1] - l[i] + MOD) % MOD + r[i - 1]) % MOD;
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
}

void init() {
    f[0] = g[0] = 1;
    for(int i = 1; i < N << 1; i++) {
        f[i] = 1ll * f[i - 1] * 2 % MOD;
        g[i] = 1ll * g[i - 1] * inv2 % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    run();
    return 0;
}
