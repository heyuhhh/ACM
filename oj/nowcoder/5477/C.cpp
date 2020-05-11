/*
 * Author:  heyuhhh
 * Created Time:  2020/5/10 14:56:58
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

int n, x;
int p[N], t[N];

ll dis[N][N];
struct Dijkstra{
    struct node{
        ll d;
        pii sta;
        bool operator < (const node &A) const {
            return d > A.d;
        }   
    };
    bool vis[N][N];
    void dij(int s) {
        priority_queue <node> q;
        memset(dis, INF, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        dis[s][1] = 0;
        q.push(node{0, MP(s, 1)});
        while(!q.empty()) {
            node cur = q.top(); q.pop();
            ll d = cur.d;
            pii sta = cur.sta;
            int now = sta.fi, had = sta.se;
            if(vis[now][had]) continue;
            vis[now][had] = 1;
            dis[now][had] = d;
            if (now <= x) {
                if (now + had <= n && p[now + had] - p[now] + d <= t[now + had]) {
                    q.push(node{p[now + had] - p[now] + d, MP(now + had, had + 1)});
                } 
                if (now > 1 && d + p[now] - p[now - 1] <= t[now - 1]) {
                    q.push(node{d + p[now] - p[now - 1], MP(now - 1, had + 1)});
                }
            } else {
                if (now - had >= 1 && p[now] - p[now - had] + d <= t[now - had]) {
                    q.push(node{p[now] - p[now - had] + d, MP(now - had, had + 1)});
                } 
                if (now < n && d + p[now + 1] - p[now] <= t[now + 1]) {
                    q.push(node{d + p[now + 1] - p[now], MP(now + 1, had + 1)});
                }               
            }
        }
    }
}solver;

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        if (t[i] == 0) x = i;
    }
    solver.dij(x);
    ll ans = min(dis[1][n], dis[n][n]);
    if (ans == dis[0][0]) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
