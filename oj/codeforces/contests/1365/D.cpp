/*
 * Author:  heyuhhh
 * Created Time:  2020/6/7 23:29:38
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

void run() {
    int n, m; cin >> n >> m;
    vector <string> mz(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> mz[i];
        for (int j = 0; j < m; j++) {
            if (mz[i][j] == 'G') ++cnt;
        }
    }
    if (cnt == 0) {
        cout << "Yes" << '\n';
        return;
    }
    const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    auto ok = [&] (int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mz[i][j] == 'B') {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (ok(x, y)) {
                        if (mz[x][y] == '#') {}
                        if (mz[x][y] == '.') mz[x][y] = '#';
                        if (mz[x][y] == 'B') {}
                        if (mz[x][y] == 'G') {
                            cout << "No" << '\n';
                            return;
                        }
                    }
                }
            }
        }
    }
    if (mz[n - 1][m - 1] == '#') {
        cout << "No" << '\n';
        return;
    }
    vector <vector <int>> d(n, vector <int>(m, -1));
    queue <pii> q;
    q.push(MP(n - 1, m - 1));
    d[n - 1][m - 1] = 0;
    while (!q.empty()) {
        pii now = q.front(); q.pop();
        int x = now.fi, y = now.se;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (ok(nx, ny) && mz[nx][ny] != '#') {
                if (d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(MP(nx, ny));   
                }
            }   
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mz[i][j] == 'B' && d[i][j] != -1) {
                cout << "No" << '\n';
                return;   
            }
            if (mz[i][j] == 'G' && d[i][j] == -1) {
                cout << "No" << '\n';
                return;
            }
        }
    }
    cout << "Yes" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
