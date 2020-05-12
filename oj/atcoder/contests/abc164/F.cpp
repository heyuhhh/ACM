/*
 * Author:  heyuhhh
 * Created Time:  2020/5/9 21:04:49
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
const int N = 500 + 5;

int n;
int s[N], t[N];
ll u[N], v[N], a[N][N];
int row[N][64], col[N][64];
int bit[N][N][64];

void run() {
    memset(bit, -1, sizeof(bit));
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i <= n; i++) cin >> u[i];
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 64; k++) {
                if (s[i] == 0 && u[i] >> k & 1) {
                    if (~bit[i][j][k]) bit[i][j][k] = 1;
                    else if (bit[i][j][k] != 1) {
                        cout << -1 << '\n';
                        return;
                    }
                }
                if (s[i] == 1 && !(u[i] >> k & 1)) {
                    if (~bit[i][j][k]) bit[i][j][k] = 0;
                    else if (bit[i][j][k] != 0) {
                        cout << -1 << '\n';
                        return;
                    }
                }
                if (t[j] == 0 && )
            }
        }      
    }
    
    for (int i = 1; i <= n; i++) if (s[i]) {
        for (int k = 0; k < 64; k++) if (u[i] >> k & 1) {
            bool f = false;
            for (int j = 1; j <= n; j++) if (a[i][j] >> k & 1) {
                f = true;
                break;
            }
            if (f) continue;
            for (int j = 1; j <= n; j++) {
                if (t[j]) {
                    if (v[j] >> k & 1) {
                        a[i][j] |= (1ll << k);
                        f = true;
                        break;
                    }
                }
            }
            if (f) continue;
            for (int j = 1; j <= n; j++) {
                if (!t[j]) {
                    if (col[j][k] + 1 < n) {
                        ++col[j][k];
                        a[i][j] |= (1ll << k);
                        f = true;
                        break;
                    }                      
                }
            }
            if (f == false) {
                cout << -1 << '\n';
                return;
            }
        } else {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] >> k & 1) {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }
    for (int j = 1; j <= n; j++) if (t[j]) {
        for (int k = 0; k < 64; k++) if (v[j] >> k & 1) {
            bool f = false;
            for (int i = 1; i <= n; i++) if (a[i][j] >> k & 1) {
                f = true;
                break;
            }
            if (f) continue;
            for (int i = 1; i <= n; i++) {
                if (s[i]) {
                    if (u[i] >> k & 1) {
                        a[i][j] |= (1ll << k);
                        f = true;
                        break;
                    }
                }
            }
            if (f) continue;
            for (int i = 1; i <= n; i++) {
                if (!s[i]) {
                    if (row[i][k] + 1 < n) {
                        ++row[i][k];
                        a[i][j] |= (1ll << k);
                        f = true;
                        break;
                    }                   
                }
            }
            if (f == false) {
                cout << -1 << '\n';
                return;
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (a[i][j] >> k & 1) {
                    cout << -1 << '\n';
                    return;
                }
            }   
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = 0;
        if (s[i]) {
            for (int j = 1; j <= n; j++) {
                x |= a[i][j];
            }
        } else {
            x = a[i][1];
            for (int j = 2; j <= n; j++) {
                x &= a[i][j];
            }
        }   
        if (x != u[i]) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int j = 1; j <= n; j++) {
        int x = 0;
        if (t[j]) {
            for (int i = 1; i <= n; i++) {
                x |= a[i][j];
            }
        } else {
            x = a[1][j];
            for (int i = 2; i <= n; i++) {
                x &= a[i][j];
            }
        }
        if (x != v[j]) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " \n"[j == n];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
