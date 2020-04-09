/*
 * Author:  heyuhhh
 * Created Time:  2020/4/8 22:36:43
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
const int N = 100 + 5;

int a[N][N];

void run() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) 
            a[i][j] = ((i + j) & 1);
    if(n * m % 2 == 0) {
        if((n + m) & 1) a[n][m] = 0;
        else {
            a[n][m] ^= 1;
            for(int i = 1; i <= n; i++) 
                for(int j = 1; j <= m; j++)
                    a[i][j] ^= 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << (a[i][j] ? "W" : "B");
        }cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
