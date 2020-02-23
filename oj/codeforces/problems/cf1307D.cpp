/*
 * Author:  heyuhhh
 * Created Time:  2020/2/18 9:39:26
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
const int N = 2e5 + 5;

int n, m, k;
int a[N];
vector <int> G[N];
int d1[N], d2[N];
bool chk[N], vis[N];

void bfs(int s, int* d) {
    memset(d, INF, (n + 1) * sizeof(int));
    queue <int> q; q.push(s); 
    d[s] = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : G[u]) {
            if(d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push(v);
            }   
        }
    }
}

void run(){
    for(int i = 1; i <= k; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bfs(1, d1); bfs(n, d2);
    for(int i = 1; i <= n; i++) {
        if(d1[i] != INF && d2[i] != INF) chk[i] = true;   
    }
    multiset <pii> s;
    for(int i = 1; i <= k; i++) {
        if(!chk[a[i]]) {
            cout << d1[n] << '\n';
            return;
        }   
        s.insert(MP(d1[a[i]], a[i]));
    }
    int ans = 0;
    for(auto it = s.begin(); it != s.end(); ++it) {
        if(it == s.begin()) continue;   
        auto it2 = it; --it2;
        ans = max(ans, min(min(d1[n], d1[it2 -> se] + d2[it -> se] + 1), d1[it -> se] + d2[it2 -> se] + 1));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> k) run();
    return 0;
}
