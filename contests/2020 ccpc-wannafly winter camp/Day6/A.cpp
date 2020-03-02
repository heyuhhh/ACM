/*
 * Author:  heyuhhh
 * Created Time:  2020/2/18 21:10:44
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
const int N = 4e5 + 5, P = 998244353, G = 3, Gi = 332748118;
const int p = 116195171;
int n, m, r[N];
ll a[N], b[N];//注意空间要开四倍
ll qpow(ll a, ll k) {
    ll ans = 1;
    while(k) {
        if(k & 1) ans = (ans * a ) % P;
        a = (a * a) % P;
        k >>= 1;
    }
    return ans;
}
void NTT(ll *A, int type, int n) {
    for(int i = 0; i < n; i++)
        if(i < r[i]) swap(A[i], A[r[i]]);
    for(int mid = 1; mid < n; mid <<= 1) {
        ll Wn = qpow( type == 1 ? G : Gi , (P - 1) / (mid << 1)); //Wn = g ^ ((p - 1) / n)  (mod p)
        for(int j = 0; j < n; j += (mid << 1)) {
            ll w = 1;
            for(int k = 0; k < mid; k++, w = (w * Wn) % P) {
                 int x = A[j + k], y = w * A[j + k + mid] % P;
                 A[j + k] = (x + y) % P,
                 A[j + k + mid] = (x - y + P) % P;
            }
        }
    }
    if(type == -1) {
        ll inv = qpow(n, P - 2);
        for(int i = 0; i < n; i++) A[i] = A[i] * inv % P;   
    }
}
void solve(ll *a, ll *b) {
    int lim = 1, L = 0;
    while(lim <= n + m) lim <<= 1, L++;
    for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
    for(int i = n + 1; i < lim; i++) a[i] = 0;  //a,b need init
    for(int i = m + 1; i < lim; i++) b[i] = 0;
    NTT(a, 1, lim); NTT(b, 1, lim);
    for(int i = 0; i < lim; i++) a[i] = a[i] * b[i] % P;
    NTT(a, -1, lim);
}

int c[N];

void run(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) {
        a[c[i]] = (a[c[i]] + qpow(qpow(p, 1ll * c[i] * c[i]), P - 2)) % P;
    }
    for(int i = 1; i <= n; i++) {
        b[c[i]] = a[c[i]];
    }
    n = m = *max_element(c + 1, c + n + 1) + 1;
    solve(a, b);
    int ans = 0;
    for(int i = 0; i <= 2 * n - 2; i++) {
        int res = 1ll * qpow(p, 1ll * i * i) * a[i] % P;
        ans = (ans + res) % P;
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
