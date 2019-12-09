/*
 * Author:  heyuhhh
 * Created Time:  2019/11/7 10:52:33
 */
#include <bits/stdc++.h>
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
const int N = 45, M = 2605;

int n, m;
char s[N];
int mp[N][N];
vector <int> g[M];

int id(int x, int y) {
    return (x - 1) * m + y;
}

bool ok(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && mp[x][y] == 0;
}

int T;
int match[M], vis[M], ban[M];
bool win[M];

bool dfs(int x) {
    if(ban[x]) return false;   
    for(int i = 0; i < sz(g[x]); i++){
        int it = g[x][i];
        if(vis[it] != T && !ban[it]) {
            vis[it] = T;
            if(match[it] == -1 || dfs(match[it])) {
                match[it] = x;
                match[x] = it;
                return true;
            }
        }   
    }
    return false;
}

void run(){
    cin >> n >> m;
    int X, Y;
    for(int i = 1; i <= n; i++) {
        cin >> (s + 1);
        for(int j = 1; j <= m; j++) {
            if(s[j] == 'X') mp[i][j] = 1;
            else if(s[j] == 'O') mp[i][j] = 0;
            else mp[i][j] = 1, X = i, Y = j;
        }
    }
    static int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if(mp[i][j]) {
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if(ok(nx, ny)) {
                    g[id(i, j)].push_back(id(nx, ny));
                    g[id(nx, ny)].push_back(id(i, j));
                }
            }
        }
    }
    memset(match, -1, sizeof(match));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if(mp[i][j]) {
            ++T; dfs(id(i, j));
        }
    }
    int k; cin >> k;
    for(int i = 1; i <= k + k; i++) {
        ban[id(X, Y)] = true;
        if(match[id(X, Y)] != -1) {
            int nw = match[id(X, Y)];
            match[id(X, Y)] = match[nw] = -1;
            ++T;
            win[i] = !dfs(nw);
        }   
        cin >> X >> Y;
    }
    vector <int> res;
    for(int i = 1; i <= k; i++) {
        if(win[2 * i - 1] && win[2 * i]) res.push_back(i);
    }
    cout << sz(res) << '\n';
    for(int i = 0; i < sz(res); i++) cout << res[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
	return 0;
}
