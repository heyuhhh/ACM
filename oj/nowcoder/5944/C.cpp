/*
 * Author:  heyuhhh
 * Created Time:  2020/6/13 16:36:39
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
const int N = 4e4 + 5, M = 8e4 + 5;

struct Edge {
    int v, next;   
} e[M];
int head[N], tot;
int d[N];
void adde(int u, int v) {
    e[tot].v = v, e[tot].next = head[u], head[u] = tot++, d[v]++;
}

int n, m;
queue <int> q;
int vis[N], T;
int f[N];

void add(int u) {
    vis[u] = T;
    f[u] ^= 1;
    for (int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if (vis[v] != T) add(v);
    }
}

int a[N], top;

void run() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adde(u, v);
    }
    f[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        a[top++] = u;
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (--d[v] == 0) {
                q.push(v);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < top; i++) {
        if (f[a[i]]) {
            ++T, ++ans;
            add(a[i]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
