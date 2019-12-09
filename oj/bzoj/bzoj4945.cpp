/*
 * Author:  heyuhhh
 * Created Time:  2019/12/2 11:21:16
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
const int N = 1e5 + 5, M = 1e5 + 5;

int n, m, d;
char s[N], t[N];
int pos[N], tot;
char x[N];

struct Edge {
    int i, j;
    char pi, pj;
}e[M];

vector<int> G[N], rG[N], vs;
int used[N], bel[N];

void adde(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v) {
    used[v] = true;
    for(int u: G[v]) {
        if(!used[u])
            dfs(u);
    }
    vs.push_back(v);
}

void rdfs(int v, int k) {
    used[v] = true;
    bel[v] = k;
    for(int u: rG[v])
        if(!used[u])
            rdfs(u, k);
}

int scc() {
    memset(used, 0, sizeof(used));
    vs.clear();
    for(int v = 1; v <= 2 * n; ++v)
        if(!used[v]) dfs(v);
    memset(used, 0, sizeof(used));
    int k = 0;
    for(int i = (int) vs.size() - 1; i >= 0; --i)
        if(!used[vs[i]]) rdfs(vs[i], k++);
    return k;
}

void work() {
    for(int i = 1; i <= 2 * n; i++) G[i].clear(), rG[i].clear();
    for(int i = 1; i <= n; i++) {
        if(t[i] == 'a') {
            x[i] = 'b';
            x[i + n] = 'c';
        } else if(t[i] == 'b') {
            x[i] = 'a';
            x[i + n] = 'c';
        } else {
            x[i] = 'a';
            x[i + n] = 'b';
        }
    }
    for(int i = 1; i <= m; i++) {
        int u = e[i].i, v = e[i].j;
        char pi = e[i].pi, pj = e[i].pj;
        if(t[u] == pi) continue;
        if(t[v] == pj) {
            if(x[u] == pi) adde(u, u + n);
            else adde(u + n, u);
        } else {
            if(x[u] == pi) {
                if(x[v] == pj) adde(u, v), adde(v + n, u + n);
                else adde(u, v + n), adde(v, u + n);
            } else {
                if(x[v] == pj) adde(u + n, v), adde(v + n, u);
                else adde(u + n, v + n), adde(v, u);
            }
        }
    }
    scc();
    for(int i = 1; i <= n; i++) {
        if(bel[i] == bel[i + n]) return;   
    }
    for(int i = 1; i <= n; i++) {
        if(bel[i] > bel[i + n]) {
            printf("%c", x[i] - 'a' + 'A');
        } else printf("%c", x[i + n] - 'a' + 'A');
    }
    cout << '\n';
    exit(0);
}

void go(int cur) {
    if(cur > tot) {
        work(); return;
    }   
    t[pos[cur]] = 'a'; go(cur + 1);
    t[pos[cur]] = 'b'; go(cur + 1);
}

void run(){
    scanf("%s", s + 1);
    for(int i = 1; i <= n; i++) {
        t[i] = s[i];
        if(s[i] == 'x') pos[++tot] = i;
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        char pi, pj;
        scanf("%d %c %d %c", &u, &pi, &v, &pj);
        pi = pi - 'A' + 'a';
        pj = pj - 'A' + 'a';
        e[i] = Edge {u, v, pi, pj};   
    }
    go(1);
    cout << -1 << '\n';
}

int main() {
    while(cin >> n >> d) run();   
    return 0;
}
