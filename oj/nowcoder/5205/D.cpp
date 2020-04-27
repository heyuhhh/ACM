/*
 * Author:  heyuhhh
 * Created Time:  2020/4/26 10:08:06
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
const int N = 100 + 5, M = 1e6 + 5;

int n, P;
int w[N];
int dis[N][N << 1];
int Pow10[M];

void run() {
    cin >> n >> P;
    Pow10[0] = 1;
    for (int i = 1; i < M; i++) {
        Pow10[i] = 1ll * Pow10[i - 1] * 10 % P;
    }
    vector <string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; s[i][j]; j++) {
            w[i] = (w[i] * 10 + s[i][j] - '0') % P;   
        }
    }
    auto bfs = [&] () {
        memset(dis, INF, sizeof(dis));
        dis[0][0] = 0;
        queue <pii> q;
        q.push(MP(0, 0));
        while (!q.empty()) {
            pii now = q.front(); q.pop();
            int u = now.fi, cur = now.se;
            for (int i = 0; i < n; i++) {
                int len = s[i].length();
                if (dis[i + 1][(1ll * cur * Pow10[len] % P + w[i]) % P] > dis[u][cur] + len) {
                    dis[i + 1][(1ll * cur * Pow10[len] % P + w[i]) % P] = dis[u][cur] + len;
                    q.push(MP(i + 1, (1ll * cur * Pow10[len] % P + w[i]) % P));
                }
            }
        }
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, dis[i][0]);   
        }
        if (ans == INF) ans = -1;
        return ans;
    };
    int ans = bfs();
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
