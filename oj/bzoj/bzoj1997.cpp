/*
 * Author:  heyuhhh
 * Created Time:  2019/11/29 18:38:08
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <cstring>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
//#define Local
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

int n, m;
int a[N], b[N], c[N];

vector<int> G[N], rG[N], vs;
int used[N], bel[N];

void adde(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v) {
    used[v] = true;
    for(int i = 0; i < sz(G[v]); i++) {
        int u = G[v][i];
        if(!used[u])
            dfs(u);
    }
    vs.push_back(v);
}

void rdfs(int v, int k) {
    used[v] = true;
    bel[v] = k;
    for(int i = 0; i < sz(G[v]); i++) {
        int u = G[v][i];
        if(!used[u])
            rdfs(u, k);
    }
}

int scc() {
    memset(used, 0, sizeof(used));
    vs.clear();
    for(int v = 1; v <= 2 * m; ++v)
        if(!used[v]) dfs(v);
    memset(used, 0, sizeof(used));
    int k = 0;
    for(int i = (int) vs.size() - 1; i >= 0; --i)
        if(!used[vs[i]]) rdfs(vs[i], k++);
    return k;
}

bool cross(int x, int y) {
    if(a[x] < a[y] && b[x] > a[y] && b[x] < b[y]) return true;
    if(a[x] < b[y] && a[x] > a[y] && b[x] > b[y]) return true;
    return false;
}

void run(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        c[x] = i;
    }
    if(m > 3 * n - 6) {
        cout << "NO" << '\n';
        return;   
    }
    for(int i = 1; i <= 2 * m; i++) {
        G[i].clear(); rG[i].clear();   
    }
    for(int i = 1; i <= m; i++) {
        a[i] = c[a[i]], b[i] = c[b[i]];
        if(a[i] > b[i]) swap(a[i], b[i]);
    }
    for(int i = 1; i <= m; i++) {
        for(int j = i + 1; j <= m; j++) {
            if(cross(i, j)) {
                adde(2 * i, 2 * j - 1);
                adde(2 * i - 1, 2 * j);
                adde(2 * j, 2 * i - 1);
                adde(2 * j - 1, 2 * i);
            }
        }
    }
    scc();
    for(int i = 1; i <= m; i++) {
        if(bel[2 * i] == bel[2 * i - 1]) {
            cout << "NO" << '\n';
            return;
        }   
    }
    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
