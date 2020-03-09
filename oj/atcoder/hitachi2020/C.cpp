/*
 * Author:  heyuhhh
 * Created Time:  2020/3/8 20:35:47
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
const int N = 2e5 + 5;

int n;
vector <int> G[N];
vector <int> v;
int col[N];
int all[3];

void find(int u, int fa, int d) {
    if(d == 3) {
        v.push_back(u);
        return;   
    }
    for(auto v : G[u]) if(v != fa) {
        find(v, u, d + 1);
    }
}

void dfs(int u, int fa) {
    v.clear();
    find(u, 0, 0);
    int cnt[3] = {0, 0, 0};
    for(auto it : v) {
        if(col[it] != -1) ++cnt[col[it]];   
    }
    if(cnt[1] && cnt[2]) col[u] = 0, --all[0];
    else if(cnt[1]) {
        if(all[2] > 0) col[u] = 2, --all[2];
        else col[u] = 0, --all[0];
    }
    else if(cnt[2]) {
        if(all[1] > 0) col[u] = 1, --all[1];
        else col[u] = 0, --all[0];
    }
    else {
        if(all[1] > 0) {
            col[u] = 1, --all[1];
        } else if(all[2] > 0){
            col[u] = 2, --all[2];   
        } else {
            col[u] = 0, --all[0];   
        }
    }
    for(auto to : G[u]) if(to != fa) dfs(to, u);
}

void run() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    all[0] = all[1] = all[2] = n / 3;
    int r = n % 3;
    if(r >= 1) ++all[1];
    if(r >= 2) ++all[2];
    memset(col, -1, sizeof(col));
    dfs(1, 0);
    for(int i = 0; i < 3; i++) {
        if(all[i] < 0) {
            cout << -1 << '\n';
            return;
        }   
    }
    int t[3] = {0, 0, 0};
    for(int i = 1; i <= n; i++) {
        if(col[i] == 0) {
            cout << 3 * t[0] + 3 << ' ';
            ++t[0];
        } else if(col[i] == 1) {
            cout << 3 * t[1] + 1 << ' ';
            ++t[1];
        } else {
            cout << 3 * t[2] + 2 << ' ';
            ++t[2];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
