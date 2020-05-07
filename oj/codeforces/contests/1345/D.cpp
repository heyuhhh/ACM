/*
 * Author:  heyuhhh
 * Created Time:  2020/5/6 23:21:04
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

int n, m;
char s[N][N];
const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
bool vis[N][N];
int cols[N], rows[N];

void dfs(int x, int y) {
    if (vis[x][y]) return ;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (s[nx][ny] == '#') dfs(nx, ny);
    }
}

void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '#') {
                ++cols[j], ++rows[i];
            }
        }       
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (cols[j] == 0 && rows[i] == 0) {
                vis[i][j] = true;
            }
        }   
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            if (vis[i][j]) ++cnt;   
        }
        cnt += rows[i];
        if (cnt == 0) {
            cout << "-1" << '\n';
            return;   
        }
        int all = rows[i];
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '.' && all && all != rows[i]) {
                cout << "-1" << '\n';
                return;
            }
            if (s[i][j] == '#') --all;
        }
    }
    for (int j = 1; j <= m; j++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i][j]) ++cnt;
        }
        cnt += cols[j];
        if (cnt == 0) {
            cout << "-1" << '\n';
            return;   
        }
        int all = cols[j];
        for (int i = 1; i <= n; i++) {
            if (s[i][j] == '.' && all && all != cols[j]) {
                cout << "-1" << '\n';
                return;
            }
            if (s[i][j] == '#') --all;
        }
    }
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] && s[i][j] == '#') {
                ++ans;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
