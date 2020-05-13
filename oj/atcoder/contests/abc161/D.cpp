/*
 * Author:  heyuhhh
 * Created Time:  2020/5/13 18:09:49
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
const int N = 11;

ll f[N][N], g[N];

void run() {
    int k; cin >> k;
    for (int i = 0; i < 10; i++) f[i][1] = 1;
    for (int t = 2; t < N; t++) {
        for (int i = 0; i < 10; i++) {
            for (int j = max(i - 1, 0); j <= min(i + 1, 9); j++) {
                f[i][t] += f[j][t - 1];
            }
        }
    }
    for (int t = 1; t < N; t++) {
        for (int i = 1; i < 10; i++) {
            g[t] += f[i][t];
        }
    }
    int t;
    for (t = 1; t < N; t++) {
        if (g[t] < k) k -= g[t];
        else break;
    }
    ll x = 0;
    int last = -1;
    for (int i = t; i >= 1; i--) {
        if (last != -1) {
            for (int j = max(last - 1, 0); j <= min(last + 1, 9); j++) {
                if (f[j][i] < k) k -= f[j][i];
                else {
                    last = j;
                    x = x * 10 + j;
                    break;
                }
            }
        } else for (int j = 1; j < 10; j++) {
            if (f[j][i] < k) k -= f[j][i];
            else {
                last = j;
                x = x * 10 + j;
                break;
            }
        }
    }
    cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
