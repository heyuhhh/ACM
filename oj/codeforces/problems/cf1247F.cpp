/*
 * Author:  heyuhhh
 * Created Time:  2020/3/9 15:13:04
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
  void err() { std::cout << '\n'; }
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

int n;
int p[N];
vector <int> G[N], sons[N];
vector <int> ans;
int deep[N];

void dfs(int u, int fa) {
    for(auto v : G[u]) if(v != fa) {
        dfs(v, u);
        deep[u] = max(deep[u], deep[v] + 1);
        sons[u].push_back(v);
    }
    sort(all(sons[u]), [&](int A, int B) {
        return deep[A] < deep[B];        
    });
}

void gao(int u, int fa) {
    cout << u << ' ';
    for(int i = 0; i < sz(sons[u]); i++) {
        gao(sons[u][i], u);
        if(i == 0) continue;
        for(int j = 0; j <= deep[sons[u][i - 1]]; j++) {
            ans.push_back(sons[u][i]);
        }   
    }
}

void run() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> p[i];
        G[p[i]].push_back(i);   
    }
    dfs(0, 0);
    gao(0, 0);
    cout << '\n';
    cout << sz(ans) << '\n';
    for(auto it : ans) cout << it << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
