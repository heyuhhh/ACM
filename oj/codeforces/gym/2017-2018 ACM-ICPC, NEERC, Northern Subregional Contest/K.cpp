/*
 * Author:  heyuhhh
 * Created Time:  2020/6/11 13:24:07
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
#include <functional>
#include <numeric>
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
const int N = 100 + 5;

int r, c, n;
int rows[N], cols[N];

void run() {
    freopen("kotlin.in", "r", stdin);
    freopen("kotlin.out", "w", stdout);
    cin >> r >> c >> n;
    int x, y;
    for (int i = 1; 1ll * i * i <= n; i++) {
        if (n % i == 0) {
            x = i - 1, y = n / i - 1;
            if (2 * x + 1 <= r && 2 * y + 1 <= c) {
                break;
            }
            x = n / i - 1, y = i - 1;
            if (2 * x + 1 <= r && 2 * y + 1 <= c) {
                break;
            }           
        }
    }
    if (2 * x + 1 <= r && 2 * y + 1 <= c) {
        for (int i = 2; i <= 2 * x; i += 2) {
            rows[i] = 1;
        }
        for (int i = 2; i <= 2 * y; i += 2) {
            cols[i] = 1;
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (rows[i] || cols[j]) {
                    cout << "#";
                } else cout << ".";
            }
            cout << '\n';
        }
    } else {
        cout << "Impossible" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
