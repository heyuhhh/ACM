/*
 * Author:  heyuhhh
 * Created Time:  2019/11/7 13:53:56
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
const int N = 10005;

int n;
int res[N];
vector <int> g[N];
int match[N], vis[N], T;

int dfs(int u) {
    for(auto v : g[u]) {
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

void run(){
    for(int i = 1; i <= n; i++) {
        int d; cin >> d;
        int l = i - d, r = i + d;
        if(l < 1) l += n;
        if(r > n) r -= n;
        if(l > r) swap(l, r);
        g[i].push_back(l);
        if(r != l) g[i].push_back(r);
    }
    int ans = 0;
    memset(match, -1, sizeof(match));
    for(int i = n; i >= 1; i--) {
        ++T; ans += dfs(i);
    }
    if(ans < n) cout << "No Answer" << '\n';
    else {
        for(int i = 1; i <= n; i++) res[match[i]] = i;
        for(int i = 1; i <= n; i++) cout << res[i] - 1 << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
	return 0;
}
