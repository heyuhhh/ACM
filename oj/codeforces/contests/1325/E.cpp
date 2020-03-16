/*
 * Author:  heyuhhh
 * Created Time:  2020/3/15 11:47:16
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
const int N = 1e6 + 5;

int n;
int a[N];
int vis1[N];
map <pii, int> vis2;
vector <int> v[N];
int mp[N], tot;

int dep[N];
vector <int> G[N];
int ans;

void dfs(int u, int fa) {
    dep[u] = dep[fa] + 1;
    for(auto v : G[u]) if(v != fa) {
        if(dep[v] == 0) dfs(v, u);
        else if(dep[u] > dep[v]) {
            ans = min(ans, dep[u] - dep[v] + 1);   
        }
    }
}

void run() {
    cin >> n;
    bool ok = false;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 1) ok = true;
        int t = a[i], num = 0;
        for(int x = 2; 1ll * x * x <= a[i]; x++) {
            if(a[i] % x == 0) {
                int cnt = 0;
                while(a[i] % x == 0) a[i] /= x, ++cnt;
                if(cnt & 1) v[i].push_back(x);
                else ++num;
            }   
        }
        if(a[i] > 1) v[i].push_back(a[i]);
        if(num && !sz(v[i])) ok = true;
        a[i] = t;
    }
    if(ok) {
        cout << 1 << '\n'; return;   
    }
    for(int i = 1; i <= n; i++) {
        if(sz(v[i]) == 1) {
            int from = 1, to = v[i][0];
            if(!mp[from]) mp[from] = ++tot;
            if(!mp[to]) mp[to] = ++tot;
            G[mp[from]].push_back(mp[to]);
            G[mp[to]].push_back(mp[from]);
            if(++vis1[v[i][0]] > 1) {
                cout << 2 << '\n'; return;
            }
        }
        if(sz(v[i]) == 2) {
            int from = v[i][0], to = v[i][1];
            if(!mp[from]) mp[from] = ++tot;
            if(!mp[to]) mp[to] = ++tot;
            G[mp[from]].push_back(mp[to]);
            G[mp[to]].push_back(mp[from]);
            if(++vis2[MP(from, to)] > 1) {
                cout << 2 << '\n'; return;   
            }
        }
    }
    ans = INF;
    for(int i = 1; i <= 1000; i++) if(mp[i]) {
        for(int j = 1; j <= tot; j++) dep[j] = 0;
        dfs(mp[i], 0);
    }
    if(ans == INF) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
