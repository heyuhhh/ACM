/*
 * Author:  heyuhhh
 * Created Time:  2020/3/17 15:23:12
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
  void err() { std::cout << '\n'; }
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
const int N = 3000 + 5;

int g[N * N];
int x, y, z;
int n, m, a, b;
int mp[N][N], tmp[N][2];
int q1[N][N], l1[N], r1[N];
int Q1[N];

void read() {
    cin >> n >> m >> a >> b;
    cin >> g[0] >> x >> y >> z;
    for(int i = 1; i < N * N; i++) g[i] = (1ll * g[i - 1] * x % z + y) % z;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            mp[i][j] = -g[(i - 1) * m + j - 1];
        }   
    }
}

void run() {
    for(int i = 1; i <= m; i++) l1[i] = 1;
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            while(l1[j] <= r1[j] && mp[q1[j][r1[j]]][j] <= mp[i][j]) r1[j]--;
            q1[j][++r1[j]] = i ;
            while(l1[j] <= r1[j] && i + 1 - q1[j][l1[j]] > a) l1[j]++;
        }
        for(int j = 1; j <= m; j++) tmp[j][0] = mp[q1[j][l1[j]]][j];
        int L1 = 1, R1 = 0;
        for(int j = 1; j <= m; j++) {
            while(L1 <= R1 && tmp[Q1[R1]][0] <= tmp[j][0]) R1--;
            Q1[++R1] = j ;
            while(L1 <= R1 && j + 1 - Q1[L1] > b) L1++;
            if(i >= a && j >= b) {
                ans -= tmp[Q1[L1]][0];
            }
        }
    }   
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    read();
    run();
    return 0;
}
