/*
 * Author:  heyuhhh
 * Created Time:  2020/5/6 15:45:04
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
const int N = 55;

struct query {
    int a, b, c, d;
}q[N];

int n, m, Q;
int ans;

void dfs(int cur, int st, vector <int>& v) {
    if (cur == n) {
        int res = 0;
        for (int i = 1; i <= Q; i++) {
            if (v[q[i].b] - v[q[i].a] == q[i].c) res += q[i].d;
        }
        ans = max(ans, res);
        return;
    }
    for (int i = st; i <= m; i++) {
        v.push_back(i);
        dfs(cur + 1, i, v);
        v.pop_back();
    }
}

void run() {
    cin >> n >> m >> Q;
    for (int i = 1; i <= Q; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        --a, --b;
        q[i] = query{a, b, c, d};
    }
    vector <int> v;
    dfs(0, 1, v);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
