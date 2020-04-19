/*
 * Author:  heyuhhh
 * Created Time:  2020/4/18 15:28:41
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
const int N = 2000 + 5;

int n, e;
int c[N];
vector <vector<int>> a(8);

#define INF 0x3f3f3f3f
template <class T>
struct Dinic{
    struct Edge{
        int v, next;
        T flow;
        Edge(){}
        Edge(int v, int next, T flow) : v(v), next(next), flow(flow) {}
    }e[N << 1];
    int head[N], tot;
    int dep[N];
    void init() {
        memset(head, -1, sizeof(head)); tot = 0;
    }
    void adde(int u, int v, T w, T rw = 0) {
        e[tot] = Edge(v, head[u], w);
        head[u] = tot++;
        e[tot] = Edge(u, head[v], rw);
        head[v] = tot++;
    }
    bool BFS(int _S, int _T) {
        memset(dep, 0, sizeof(dep));
        queue <int> q; q.push(_S); dep[_S] = 1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = head[u]; ~i; i = e[i].next) {
                int v = e[i].v;
                if(!dep[v] && e[i].flow > 0) {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return dep[_T] != 0;
    }
    T dfs(int _S, int _T, T a) {
        T flow = 0, f;
        if(_S == _T || a == 0) return a;
        for(int i = head[_S]; ~i; i = e[i].next) {
            int v = e[i].v;
            if(dep[v] != dep[_S] + 1) continue;
            f = dfs(v, _T, min(a, e[i].flow));
            if(f) {
                e[i].flow -= f;
                e[i ^ 1].flow += f;
                flow += f;
                a -= f;
                if(a == 0) break;
            }
        }
        if(!flow) dep[_S] = -1;
        return flow;
    }
    T dinic(int _S, int _T) {
        T max_flow = 0;
        while(BFS(_S, _T)) max_flow += dfs(_S, _T, INF);
        return max_flow;
    }
};

Dinic <int> solver;

bool chk(int x) {
    solver.init();   
    for(int i = 1; i <= 7; i++) {
        int t = (x - 1) / 7, r = (x - 1) % 7 + 1;
        solver.adde(0, i, (t + (i <= r) * e));
    }
    for(int i = 1; i <= 7; i++) {
        for(auto j : a[i]) {
            solver.adde(i, j + 7, INF);
        }
    }
    int T = 3000, sum = 0;
    for(int i = 1; i <= n; i++) {
        solver.adde(i + 7, T, c[i]);
        sum += c[i];
    }
    return solver.dinic(0, T) >= sum;
}

void run() {
    cin >> n >> e;
    for(int i = 1; i <= n; i++) {
        cin >> c[i]; int x; cin >> x;
        for(int j = 1; j <= x; j++) {
            int t; cin >> t;
            a[t].push_back(i);
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
    run();
    return 0;
}
