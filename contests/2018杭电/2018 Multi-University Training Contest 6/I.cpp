/*
 * Author:  heyuhhh
 * Created Time:  2020/5/15 14:59:03
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
const int N = 1e5 + 5;

int n;
vector <int> rG[N];
vector <pii> edges;
int f[N];

int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) f[fx] = fy;
}

int rdfs(int u) {
    int res = 1;
    for (auto v : rG[u]) {
        res += rdfs(v);
    }
    return res;
}

void run() {
    cin >> n;
    edges.clear();
    for (int i = 1; i <= n; i++) rG[i].clear();
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= n; i++) {
        int x; string s;
        cin >> x >> s;
        if (s[0] == 'v') {
            merge(i, x);
            rG[x].push_back(i);
        } else {
            edges.push_back(MP(i, x));
        }
    }
    int ans1 = 0, ans2 = 0;
    for (auto edge : edges) {
        int u = edge.fi, v = edge.se;
        if (find(u) == find(v)) {
            ans2 += rdfs(v);
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
