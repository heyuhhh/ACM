/*
 * Author:  heyuhhh
 * Created Time:  2020/2/15 15:10:04
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
const int N = 1000 + 5, M = 45;

int n, m, k;
int a[N][N];
vector <pii> v[M];
int dis[M][N][N];
bool vis[M], chk[N][N];

void bfs(int col) {
    queue <pii> q;
    memset(dis[col], INF, sizeof(dis[col]));
    memset(chk, 0, sizeof(chk));
    memset(vis, 0, sizeof(vis));
    for(auto it : v[col]) {
        q.push(MP(it.fi, it.se));
        dis[col][it.fi][it.se] = 0;
        chk[it.fi][it.se] = true;
    }
    vis[col] = 1;
    static const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    auto ok = [&](int x, int y) {
        return x >= 1 && x <= n && y >= 1 && y <= m;   
    };
    while(!q.empty()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();
        if(!vis[a[x][y]]) {
            for(auto it : v[a[x][y]]) {
                int nx = it.fi, ny = it.se;
                if(dis[col][nx][ny] > dis[col][x][y] + 1) {
                    dis[col][nx][ny] = dis[col][x][y] + 1;
                    if(!chk[nx][ny]) {
                        chk[nx][ny] = true;
                        q.push(MP(nx, ny));   
                    }
                }
            }
            vis[a[x][y]] = 1;
        }   
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(ok(nx, ny) && dis[col][nx][ny] > dis[col][x][y] + 1) {
                dis[col][nx][ny] = dis[col][x][y] + 1;
                if(!chk[nx][ny]) {
                    chk[nx][ny] = true;
                    q.push(MP(nx, ny));   
                }
            }
        }
    }
}

void run(){
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            v[a[i][j]].push_back(MP(i, j));
        }   
    }
    for(int i = 1; i <= k; i++) {
        bfs(i);   
    }
    int q; cin >> q;
    while(q--) {
        int r1, r2, c1, c2; cin >> r1 >> c1 >> r2 >> c2;
        int ans = abs(r1 - r2) + abs(c1 - c2);
        for(int i = 1; i <= k; i++) {
            ans = min(ans, dis[i][r1][c1] + dis[i][r2][c2] + 1);   
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> k) run();
    return 0;
}
