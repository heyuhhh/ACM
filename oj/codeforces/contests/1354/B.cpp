/*
 * Author:  heyuhhh
 * Created Time:  2020/5/17 17:31:08
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
const int N = 2e5 + 5;

char s[N];

int last[N][4];

void run() {
    cin >> (s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            last[i][j] = last[i - 1][j];
        }
        last[i][s[i] - '0'] = i;   
    }
    int ans = INF;
    for (int i = 3; i <= n; i++) {
        if (s[i] == '1') {
            int p1 = last[i][2], p2 = last[i][3];
            int p = min(p1, p2);
            if (p) ans = min(ans, i - p + 1);
        } else if(s[i] == '2') {
            int p1 = last[i][1], p2 = last[i][3];
            int p = min(p1, p2);
            if (p) ans = min(ans, i - p + 1);
        } else {
            int p1 = last[i][1], p2 = last[i][2];
            int p = min(p1, p2);
            if (p) ans = min(ans, i - p + 1);
        }
    }
    if (ans == INF) ans = 0;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
