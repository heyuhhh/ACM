/*
 * Author:  heyuhhh
 * Created Time:  2019/12/22 16:21:48
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
const int N = 1e6 + 5;

vector <int> G[N];

int n;
int L[N], R[N];
int tot;

void dfs(int u, int fa) {
    for(auto v : G[u]) if(v != fa) {
        L[v] = ++tot;
    }   
    R[u] = ++tot;
    for(int i = sz(G[u]) - 1; i >= 0; i--) {
        int v = G[u][i];
        if(v != fa) dfs(v, u);
    }
}

void run(){
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);   
    }
    L[1] = ++tot;
    dfs(1, 0);
    for(int i = 1; i <= n; i++) {
        cout << L[i] << ' ' << R[i] << '\n';   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
