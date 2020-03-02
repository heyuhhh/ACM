/*
 * Author:  heyuhhh
 * Created Time:  2020/2/9 17:58:39
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
const int N = 18;

int n, m;
int f[1 << N], ok[1 << N];
int a[N][N];

void run(){
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    for(int i = 0; i < 1 << n; i++) {
        ok[i] = 1;
        for(int j = 1; j <= n; j++) {
            if(i >> (j - 1) & 1) {
                for(int k = j + 1; k <= n; k++) {
                    if(i >> (k - 1) & 1) {
                        if(a[j][k]) ok[i] = 0;
                    }
                }
            }
        }
    }
    memset(f, INF, sizeof(f));
    f[0] = 0;
    for(int i = 0; i < 1 << n; i++) {
        for(int j = i; j > 0; j = (j - 1) & i) {
            if(ok[j]) f[i] = min(f[i], f[i ^ j] + 1);
        }
    }
    cout << f[(1 << n) - 1] - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m) run();
    return 0;
}
