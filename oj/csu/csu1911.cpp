/*
 * Author:  heyuhhh
 * Created Time:  2020/4/23 10:16:09
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
const int N = 1e5 + 5, M = 18;

void FWT_or(ll *a, int n, int op) {
    for(int i = 1; i < n; i <<= 1)
        for(int p = i << 1, j = 0; j < n; j += p)
            for(int k = 0; k < i; k++)
                if(op == 1) a[i + j + k] = (a[j + k] + a[i + j + k]) ;
                else a[i + j + k] = (a[i + j + k] - a[j + k]) ;
}

int n, m, _;
char s[M];
ll a[1 << M], b[1 << M], c[1 << M];

void run() {
    cin >> n >> m;
    for (int i = 0; i < 1 << m; i++) a[i] = b[i] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int len = strlen(s);
        int x = 0;
        for (int j = len - 1; j >= 0; j--) {
            if (s[j] == '1') x += (1 << (len - j - 1));
        }
        ++a[x];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int len = strlen(s);
        int x = 0;
        for (int j = len - 1; j >= 0; j--) {
            if (s[j] == '1') x += (1 << (len - j - 1));
        }
        ++b[x];
    } 
    FWT_or(a, 1 << m, 1), FWT_or(b, 1 << m, 1);
    for (int i = 0; i < 1 << m; i++) c[i] = a[i] * b[i] ;
    FWT_or(c, 1 << m, -1);
    cout << "Case #" << ++_ << ":\n";
    int q; cin >> q;
    while (q--) {
        cin >> s;
        int len = strlen(s);
        int x = 0;
        for (int j = len - 1; j >= 0; j--) {
            if (s[j] == '1') x += (1 << (len - j - 1));
        }
        cout << c[x] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--) 
    run();
    return 0;
}
