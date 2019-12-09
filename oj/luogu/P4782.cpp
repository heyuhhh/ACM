/*
 * Author:  heyuhhh
 * Created Time:  2019/11/29 16:28:13
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
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
const int N = 2e6 + 5;

int n, m;

vector<int> vs;
int used[N], bel[N];

struct Edge{
    int next, v;
}e[N], re[N];
int head[N], tot;
int rhead[N], rtot;
void adde(int u, int v) {
    e[tot] = Edge {head[u], v};
    head[u] = tot++;
    re[rtot] = Edge {rhead[v], u};
    rhead[v] = rtot++;
}

void dfs(int v) {
    used[v] = true;
    for(int i = head[v]; i != -1; i = e[i].next) {
        int u = e[i].v;
        if(!used[u])
            dfs(u);
    }
    vs.push_back(v);
}

void rdfs(int v, int k) {
    used[v] = true;
    bel[v] = k;
    for(int i = rhead[v]; i != -1; i = re[i].next) {
        int u = re[i].v;
        if(!used[u])
            rdfs(u, k);
    }
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

void run(){
    memset(head, -1, sizeof(head));
    memset(rhead, -1, sizeof(rhead));
    for(int i = 1; i <= m; i++) {
        int xi, xj, a, b;
        cin >> xi >> a >> xj >> b;
        if(a) {
            if(b) adde(2 * xi, 2 * xj - 1), adde(2 * xj, 2 * xi - 1);
            else adde(2 * xi, 2 * xj), adde(2 * xj - 1, 2 * xi - 1);
        } else {
            if(b) adde(2 * xi - 1, 2 * xj - 1), adde(2 * xj, 2 * xi);
            else adde(2 * xi - 1, 2 * xj), adde(2 * xj - 1, 2 * xi);
        }
    }
    int tot = scc();
    for(int i = 1; i <= n; i++) {
        if(bel[2 * i] == bel[2 * i - 1]) {
            cout << "IMPOSSIBLE" << '\n';
            return;
        }   
    }
    cout << "POSSIBLE" << '\n';
    for(int i = 1; i <= n; i++) {
        if(bel[2 * i] < bel[2 * i - 1]) cout << 1;
        else cout << 0;   
        cout << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m) run();
    return 0;
}
