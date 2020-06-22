/*
 * Author:  heyuhhh
 * Created Time:  2020/6/22 14:05:49
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
const int N = 1e5 + 5;

int n, m, k;
struct node {
    int x, y;
    int cost;
    int r;
    int dir;
    bool operator < (const node& A) const {
        if (cost == A.cost) return r > A.r;
        return cost > A.cost;
    }
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void run() {
    cin >> n >> m >> k;
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    --sx, --sy;
    --ex, --ey;
    vector <string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    priority_queue <node> q;
    vector <vector <vector <int>>> dis(n, vector <vector <int>>(m, vector <int>(4, INF)));
    vector <vector <vector <bool>>> vis(n, vector <vector <bool>>(m, vector <bool>(4, false)));
    for (int i = 0; i < 4; i++) {
        dis[sx][sy][i] = 0;
        q.push(node{sx, sy, 0, 0, i});
    }
    while (!q.empty()) {
        node now = q.top(); q.pop();
        int x = now.x, y = now.y;
        int cost = now.cost, r = now.r;
        int dir = now.dir;
        if (vis[x][y][dir]) continue;
        vis[x][y][dir] = true;
        dis[x][y][dir] = cost + (r > 0 ? 1 : 0);
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && s[nx][ny] != '@') {
                if (d == dir && r < k) {
                    q.push(node{nx, ny, cost, r + 1, d});
                } else {
                    q.push(node{nx, ny, cost + 1, 1, d});
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < 4; i++) {
        ans = min(ans, dis[ex][ey][i]);
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
