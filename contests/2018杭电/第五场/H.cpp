/*
 * Author:  heyuhhh
 * Created Time:  2020/5/8 11:54:49
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
const int N = 1e5 + 5, M = 13;

int n;
int f[N][M], fl[N][M], fr[N][M];
int a[N], b[M], m;
char s[N];
int ans, l, r;

void dp(int L, int R) {
    for (int i = 0; i <= m; i++) {
        f[0][i] = 0;
        fl[0][i] = fr[0][i] = -1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            fl[i][j] = fl[i - 1][j];
            fr[i][j] = fr[i - 1][j];
            if (a[i] == b[j]) {
                ++f[i][j];
                if (a[i] == R && fl[i][j] == -1) fl[i][j] = i;
                if (a[i] == L) fr[i][j] = i;
            }
            if (f[i][j - 1] > f[i][j]) {
                f[i][j] = f[i][j - 1];
                fl[i][j] = fl[i][j - 1];
                fr[i][j] = fr[i][j - 1];
            }
        }
    }
    if (L == 1 && R == 1) {
        l = r = 1;
        ans = f[n][m];
    } else {
        if (f[n][m] > ans && fl[n][m] != -1 && fr[n][m] != -1 && fl[n][m] < fr[n][m]) {
            ans = f[n][m];
            l = fl[n][m], r = fr[n][m];   
        }
    }
}

void run() {
    cin >> n >> (s + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = s[i] - '0';
    }
    m = 0;
    for (int i = 0; i < 10; i++) {
        b[++m] = i;
    }
    dp(1, 1);
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            m = 0;
            for (int k = 0; k <= i; k++) b[++m] = k;
            for (int k = j; k >= i; k--) b[++m] = k;
            for (int k = j; k < 10; k++) b[++m] = k;
            dp(i, j);
        }
    }
    cout << ans << ' ' << l << ' ' << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
