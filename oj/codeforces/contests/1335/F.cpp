/*
 * Author:  heyuhhh
 * Created Time:  2020/4/14 9:05:02
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <numeric>
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
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
void run() {
    int n, m; cin >> n >> m;
    vector <string> c(n), mp(n);
    vector <vector<int>> deg(n, vector<int>(m)), dist(n, vector<int>(m, -1));
    vector <vector<pii>> to(n, vector<pii>(m));
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) {
        cin >> mp[i];
        for(int j = 0; j < m; j++) {
            if(mp[i][j] == 'U') ++deg[i - 1][j], to[i][j] = MP(i - 1, j);
            if(mp[i][j] == 'D') ++deg[i + 1][j], to[i][j] = MP(i + 1, j);
            if(mp[i][j] == 'L') ++deg[i][j - 1], to[i][j] = MP(i, j - 1);
            if(mp[i][j] == 'R') ++deg[i][j + 1], to[i][j] = MP(i, j + 1);
        }
    }
    vector <pii> que;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(deg[i][j] == 0) que.push_back(MP(i, j));
        }
    }
    for(int i = 0; i < sz(que); i++) {
        int x = que[i].fi, y = que[i].se;
        int nx = x, ny = y;
        if(mp[x][y] == 'U') --nx;
        if(mp[x][y] == 'D') ++nx;
        if(mp[x][y] == 'L') --ny;
        if(mp[x][y] == 'R') ++ny;
        if(--deg[nx][ny] == 0) {
            que.push_back(MP(nx, ny));   
        }
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) if(deg[i][j] > 0 && dist[i][j] == -1) {
            int len = 0;
            que.clear();
            que.push_back(MP(i, j));
            dist[i][j] = 0;
            for(int t = 0; t < sz(que); t++) {
                int x = que[t].fi, y = que[t].se;
                if(deg[x][y] > 0) ++len;
                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1 && to[nx][ny] == MP(x, y)) {
                        que.push_back(MP(nx, ny));
                        dist[nx][ny] = dist[x][y] + 1;
                    }
                }
            }
            vector <int> f(len);
            for(auto it : que) {
                if(c[it.fi][it.se] == '0') f[dist[it.fi][it.se] % len] = 1;
            }
            ans1 += len;
            ans2 += accumulate(all(f), 0);
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
