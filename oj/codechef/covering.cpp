/*
 * Author:  heyuhhh
 * Created Time:  2020/4/25 12:22:57
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
const int N = 20, MOD = 1e9 + 7;

int n;
int f[1 << N], g[1 << N], h[1 << N];
int a[1 << N];

void FWT_or(int *a, int n, int op) {
    for(int i = 1; i < n; i <<= 1)
        for(int p = i << 1, j = 0; j < n; j += p)
            for(int k = 0; k < i; k++)
                if(op == 1) a[i + j + k] = (a[j + k] + a[i + j + k]) % MOD;
                else a[i + j + k] = (a[i + j + k] + MOD - a[j + k]) % MOD;
}

void run() {
    cin >> n;
    for (int i = 0; i < 1 << n; i++) {
        cin >> f[i];   
    }
    for (int i = 0; i < 1 << n; i++) {
        cin >> g[i];   
    }
    for (int i = 0; i < 1 << n; i++) {
        cin >> h[i];   
    }
    FWT_or(f, 1 << n, 1);    
    FWT_or(g, 1 << n, 1);    
    FWT_or(h, 1 << n, 1);
    for (int i = 0; i < 1 << n; i++) {
        a[i] = 1ll * f[i] * g[i] % MOD * h[i] % MOD;
    }
    FWT_or(a, 1 << n, -1);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < 1 << n; i++) {
            if (!(i >> j & 1)) a[i] = (a[i] + a[i ^ (1 << j)]) % MOD;
        }   
    }
    int ans = 0;
    for (int i = 0; i < 1 << n; i++) {
        ans = (ans + a[i]) % MOD;   
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
