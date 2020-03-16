/*
 * Author:  heyuhhh
 * Created Time:  2020/3/12 16:51:22
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <cstdio>
#include <map>
#include <queue>
#include <iomanip>
#include <stdlib.h>
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
const int N = 50 + 5;
const int dx[] = {1, 2, -2, -1, 0, 0}, dy[] = {1, 0, 0, -1, 2, -2};

int n;
int mp[N][N];

int query(int r1, int c1, int r2, int c2) {
	if(r1 > r2) {
		swap(r1, r2), swap(c1, c2);
	} 
	if(c1 > c2) {
		swap(r1, r2), swap(c1, c2);
	} 
    cout << "?" << ' ' << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << endl;
    int x; cin >> x;
    return x;
}

void run() {
    cin >> n;
    memset(mp, -1, sizeof(mp));
    mp[1][1] = 1, mp[1][2] = mp[n][n] = 0;
    auto chk = [&](int x, int y) {
        return x >= 1 && x <= n && y >= 1 && y <= n && mp[x][y] == -1;  
    };
    auto bfs = [&](int sx, int sy) {
        queue <pii> q;
        q.push(MP(sx, sy));
        while(!q.empty()) {
            pii now = q.front(); q.pop();
            int x = now.fi, y = now.se;
            for(int i = 0; i < 6; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if(chk(nx, ny)) {
                    int t = query(x, y, nx, ny);
                    if(t) mp[nx][ny] = mp[x][y];
                    else mp[nx][ny] = 1 - mp[x][y];
                    q.push(MP(nx, ny));
                }
            }
        }       
    };
    bfs(1, 1), bfs(1, 2);
    int x = 1, y = 1;
    while(mp[x + 2][y + 2] == 1) x += 2, y += 2;
    bool f = false;
    int t = query(x, y, x + 1, y + 2);
    if(t && mp[x][y] != mp[x + 1][y + 2]) f = true;
    if(!t) {
        int tt = query(x, y + 1, x + 2, y + 2);
        if(tt && mp[x][y + 1] != mp[x + 2][y + 2]) f = true;
        if(!tt) {
            if(mp[x][y + 1] == mp[x + 1][y + 2]) {
                if(mp[x][y + 1] == mp[x][y + 2]) f = true;
            } else {
                if(!mp[x][y + 1]) f = true;
            }              
        }
    }
    for(int i = 1; i <= n && f; i++) {
        for(int j = 1; j <= n; j++) if((i + j) & 1) {
            mp[i][j] = 1 - mp[i][j];   
        }
    }
    cout << "!" << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << mp[i][j];
        }   
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

