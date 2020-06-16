/*
 * Author:  heyuhhh
 * Created Time:  2020/6/13 18:31:10
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
#pragma GCC optimize(2)
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

int n, m;
int a[N];
ll d[N];
int vis[N], T;
struct Edge {
    int v, w, next;   
} e[N << 1];
int head[N], tot;
void adde(int u, int v, int w) {
    e[tot].v = v, e[tot].w = w, e[tot].next = head[u], head[u] = tot++;   
}
pair<pii, int> edges[N];

struct node {
    ll r; int t;
    bool operator < (const node& A) const {
        return r < A.r;
    }
};
priority_queue <node> q;
bool check(ll x) {
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= m; ++i) {
        q.push(node{x, a[i]});
        d[a[i]] = x;
    }
    while (!q.empty()) {
        node now = q.top(); q.pop();
        int u = now.t;
        ll dis = now.r;
        if (vis[u] == T) continue;
        vis[u] = T;
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].v, w = e[i].w;
            if (dis - w > d[v]) {
                d[v] = dis - w;
                q.push(node {d[v], v});
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        int u = edges[i].fi.fi, v = edges[i].fi.se, w = edges[i].se;
        if (d[u] + d[v] < w) return false;
    }
    return true;
}

void run() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v, w; 
        scanf("%d%d%d", &u, &v, &w);
        w <<= 1;
        edges[i] = MP(MP(u, v), w);
        adde(u, v, w);
        adde(v, u, w);
    }
    random_shuffle(edges + 1, edges + n);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &a[i]);
    }
    ll l = 0, r = 1e14, mid;
    while (l < r) {
        ++T;
        mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%lld\n", l);
}

int main() {
    run();
    return 0;
}
