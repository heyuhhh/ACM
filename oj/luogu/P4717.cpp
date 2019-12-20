/*
 * Author:  heyuhhh
 * Created Time:  2019/12/20 20:28:11
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
const int N = (1 << 17), MOD = 998244353;

int n;
int a[N], b[N], c[N];

void FWT_or(int *a, int n, int op) {
    for(int i = 1; i < n; i <<= 1)
        for(int p = i << 1, j = 0; j < n; j += p)
            for(int k = 0; k < i; k++)
                if(op == 1) a[i + j + k] = (a[j + k] + a[i + j + k]) % MOD;
                else a[i + j + k] = (a[i + j + k] + MOD - a[j + k]) % MOD;
}
void FWT_and(int *a, int n, int op) {
    for(int i = 1; i < n; i <<= 1)
        for(int p = i << 1, j = 0; j < n; j += p)
            for(int k = 0; k < i; k++)
                if(op == 1) a[j + k] = (a[j + k] + a[i + j + k]) % MOD;
                else a[j + k] = (a[j + k] + MOD - a[i + j + k]) % MOD;      
}
void FWT_xor(int *a, int n, int op) {
    static int inv2 = (MOD + 1) / 2;
    for(int i = 1; i < n; i <<= 1)
        for(int p = i << 1, j = 0; j < n; j += p)
            for(int k = 0; k < i; k++) {
                int X = a[j + k], Y = a[i + j + k];
                a[j + k] = (X + Y) % MOD; a[i + j + k] = (X + MOD - Y) % MOD;
                if(op == -1) a[j + k] = 1ll * a[j + k] * inv2 % MOD, a[i + j + k] = 1ll * a[i + j + k] * inv2 % MOD;
            }                
}

void run(){
    int l = 1 << n;
    for(int i = 0; i < l; i++) cin >> a[i];
    for(int i = 0; i < l; i++) cin >> b[i];
    
    FWT_or(a, l, 1); FWT_or(b, l, 1);
    for(int i = 0; i < l; i++) c[i] = 1ll * a[i] * b[i] % MOD;
    FWT_or(c, l, -1);
    for(int i = 0; i < l; i++) cout << c[i] << " \n"[i == l - 1];
    FWT_or(a, l, -1); FWT_or(b, l, -1);
    
    FWT_and(a, l, 1); FWT_and(b, l, 1);
    for(int i = 0; i < l; i++) c[i] = 1ll * a[i] * b[i] % MOD;
    FWT_and(c, l, -1);
    for(int i = 0; i < l; i++) cout << c[i] << " \n"[i == l - 1];
    FWT_and(a, l, -1); FWT_and(b, l, -1);
    
    FWT_xor(a, l, 1); FWT_xor(b, l, 1);
    for(int i = 0; i < l; i++) c[i] = 1ll * a[i] * b[i] % MOD;
    FWT_xor(c, l, -1);
    for(int i = 0; i < l; i++) cout << c[i] << " \n"[i == l - 1];
    FWT_xor(a, l, -1); FWT_xor(b, l, -1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
