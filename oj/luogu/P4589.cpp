/*
 * Author:  heyuhhh
 * Created Time:  2019/11/6 10:20:13
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
const int N = 500 + 5;

int n, m, T;
int v[N];
int g[N][N];
int match[N], vis[N];
int tmp[N], tot;

int dfs(int u) {
    for(int i = 1; i <= tot; i++) {
        if(vis[i] != T && g[tmp[u]][tmp[i]]) {
            vis[i] = T;
            if(match[i] == -1 || dfs(match[i])) {
                match[i] = u;
                return 1;
            }
        }
    }   
    return 0;
}

bool chk(int x) {
    tot = 0;
    for(int i = 1; i <= m; i++) if(v[i] < x) tmp[++tot] = i;
    int ans = tot;
    for(int i = 1; i <= tot; i++) match[i] = -1;
    for(int i = 1; i <= tot; i++) {
        ++T; ans -= dfs(i);
    }
    return ans <= n + 1;
}

void run(){
    cin >> n >> m;
    int Max = 0;
    for(int i = 1; i <= m; i++) {
        cin >> v[i];
        Max = max(Max, v[i]);
        int k; cin >> k;
        for(int j = 1; j <= k; j++) {
            int x; cin >> x;
            g[i][x] = 1;
        }
    }
    for(int k = 1; k <= m; k++)
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= m; j++) 
                g[i][j] |= (g[i][k] & g[k][j]);
    if(chk(INF)) {
        cout << "AK" << '\n';
        return;
    }
    int l = 0, r = Max + 1, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(chk(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
	return 0;
}
