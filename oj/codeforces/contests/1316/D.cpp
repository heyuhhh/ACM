/*
 * Author:  heyuhhh
 * Created Time:  2020/3/5 8:32:12
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
const int N = 1e3 + 5;

int n;
int mp[N][N];
int x[N][N], y[N][N];

const int dx[] = {0, -1, 1, 0, 0}, dy[] = {0, 0, 0, -1, 1};
bool vis[N][N];

void go(int sx, int sy, int px, int py, int dir) {
    int nx = px + dx[dir], ny = py + dy[dir];
    if(nx < 1 || nx > n || ny < 1 || ny > n || vis[nx][ny]) return;
    if(x[nx][ny] != sx || y[nx][ny] != sy) return;
    vis[nx][ny] = true;
    if(dir == 1) mp[nx][ny] = 2;
    else if(dir == 2) mp[nx][ny] = 1;
    else if(dir == 3) mp[nx][ny] = 4;
    else mp[nx][ny] = 3;
    for(int i = 1; i <= 4; i++) go(sx, sy, nx, ny, i);
}

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> x[i][j] >> y[i][j];
            if(x[i][j] == i && y[i][j] == j) {
                mp[i][j] = 5;  
            }
        }   
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(mp[i][j] == 5) {
                vis[i][j] = true; 
                for(int k = 1; k <= 4; k++) go(i, j, i, j, k);   
            }
        }   
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j++) {
            if(!mp[i][j]) {
                if(x[i][j] != -1 || y[i][j] != -1) {
                    cout << "INVALID" << '\n';
                    return;                         
                }
                bool f = false;
                for(int k = 1; k <= 4; k++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx < 1 || nx > n || ny < 1 || ny > n || vis[nx][ny]) continue;
                    f = true;
                    mp[i][j] = k;
                    break;
                }
                if(f == false) {
                    cout << "INVALID" << '\n';
                    return;   
                }
            }
        }   
    }
    cout << "VALID" << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(mp[i][j] == 1) cout << "U";
            if(mp[i][j] == 2) cout << "D";
            if(mp[i][j] == 3) cout << "L";
            if(mp[i][j] == 4) cout << "R";
            if(mp[i][j] == 5) cout << "X";
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
