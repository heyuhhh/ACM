/*
 * Author:  heyuhhh
 * Created Time:  2019/11/7 15:27:40
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
const int N = 255, M = 1e5 + 5;

int n, m, k;
int val[N][N];

struct Edge{
    int v, next;
}e[M];
int head[N], tot;
void adde(int u, int v) {
    e[tot].v = v; e[tot].next = head[u]; head[u] = tot++;
}

int T, vis[N];
int match[N];

int dfs(int u) {
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(vis[v] != T) {
            vis[v] = T;
            if(match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;   
}

bool chk(int x) {
    memset(head, -1, sizeof(head)); tot = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(val[i][j] <= x) adde(i, j);
        }
    }
    memset(match, -1, sizeof(match));
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ++T; ans += dfs(i);
    }
    return ans >= n - k + 1;
}

void run(){
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> val[i][j];
        }
    }
    int l = 1, r = INF, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(chk(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> k) run();
	return 0;
}
