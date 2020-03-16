/*
 * Author:  heyuhhh
 * Created Time:  2020/3/15 21:59:25
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
const int N = 1e5 + 5, M = 5e5 + 5;

int n, m;
bool vis[N << 2];

void run() {
    cin >> n >> m;
    for(int i = 1; i <= 3 * n; i++) vis[i] = false;
    vector <int> edges;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        if(!vis[u] && !vis[v]) {
            vis[u] = vis[v] = true;
            edges.push_back(i);   
        }
    }
    if(sz(edges) >= n) {
        edges.resize(n);
        cout << "Matching" << '\n';
        for(auto it : edges) cout << it << ' ';
        cout << '\n';   
    } else {
        cout << "IndSet" << '\n';
        int cnt = n;
        for(int i = 1; i <= 3 * n; i++) if(!vis[i] && cnt) {
            --cnt; cout << i << ' ';
        }   
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
