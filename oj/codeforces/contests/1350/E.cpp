/*
 * Author:  heyuhhh
 * Created Time:  2020/5/12 23:56:30
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
const int N = 1e3 + 5;
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

int n, m, t;
char s[N][N];
int a[N][N], dis[N][N];
bool vis[N][N];

void run() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
        for (int j = 1; j <= m; j++) {
            a[i][j] = (s[i][j] - '0');
        }
    }
    auto ok = [&] (int nx, int ny) {
        return nx >= 1 && nx <= n && ny >= 1 && ny <= m;
    };
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j]) {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (ok(x, y) && a[x][y] == a[i][j]) {
                        vis[i][j] = true;
                    }
                }
            }
        }
    }
    memset(dis, INF, sizeof(dis));
    queue <pii> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j]) {
                q.push(MP(i, j));
                dis[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        int x = cur.fi, y = cur.se;
        auto ok = [&] (int nx, int ny) {
            return nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && dis[nx][ny] > dis[x][y] + 1;
        };
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (ok(nx, ny)) {
                dis[nx][ny] = dis[x][y] + 1;
                vis[nx][ny] = true;
                q.push(MP(nx, ny));
            }
        }
    }
    while (t--) {
        int i, j; ll p;
        cin >> i >> j >> p;
        if (p <= dis[i][j] || dis[i][j] == INF) {
            cout << a[i][j] << '\n';
        } else {
            int r = (p - dis[i][j]) % 2;
            cout << (a[i][j] ^ r) << '\n';
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
