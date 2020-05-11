/*
 * Author:  heyuhhh
 * Created Time:  2020/5/10 14:34:55
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
const int N = 10 + 1;

int w, h, k;
char s[N][N];

void dfs(int cur, char s[][N]) {
    if (cur == k) return;   
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= h; j++) if (s[i][j] == 'R') {
            for (int k = j; k >= 1; k--) {
                if (k - 1 < 1 || s[i][k - 1] == 'X' || s[i][k - 1] == 'R') {
                    if (s[i][k] == 'D') {
                        cout << "YES" << '\n';
                        exit(0);   
                    }
                    swap(s[i][k], s[i][j]);
                    dfs(cur + 1, s);
                    swap(s[i][k], s[i][j]);
                    break;
                }
            }
            for (int k = j; k <= h; k++) {
                if (k + 1 > h || s[i][k + 1] == 'X' || s[i][k + 1] == 'R') {
                    if (s[i][k] == 'D') {
                        cout << "YES" << '\n';
                        exit(0);   
                    }
                    swap(s[i][k], s[i][j]);
                    dfs(cur + 1, s);
                    swap(s[i][k], s[i][j]);
                    break;
                }   
            }
            for (int k = i; k >= 1; k--) {
                 if (k - 1 < 1 || s[k - 1][j] == 'X' || s[k - 1][j] == 'R') {
                    if (s[k][j] == 'D') {
                        cout << "YES" << '\n';
                        exit(0);   
                    }
                    swap(s[k][j], s[i][j]);
                    dfs(cur + 1, s);
                    swap(s[k][j], s[i][j]);
                    break;
                }                  
            }
            for (int k = i; k <= w; k++) {
                 if (k + 1 > w || s[k + 1][j] == 'X' || s[k + 1][j] == 'R') {
                    if (s[k][j] == 'D') {
                        cout << "YES" << '\n';
                        exit(0);   
                    }
                    swap(s[k][j], s[i][j]);
                    dfs(cur + 1, s);
                    swap(s[k][j], s[i][j]);
                    break;
                }                  
            }
        }   
    }
}

void run() {
    cin >> w >> h >> k;
    swap(w, h);
    for (int i = 1; i <= w; i++) {
        cin >> (s[i] + 1);
    }
    dfs(0, s);
    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
