/*
 * Author:  heyuhhh
 * Created Time:  2020/5/24 14:40:58
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
#include <functional>
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

void run() {
    int n, m, A, B;
    cin >> n >> m >> A >> B;
    int k = B - A + 1;
    vector <vector <int>> G(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if (k == 1) {
        if (m) {
            cout << "No" << '\n';
        } else {
            cout << "Yes" << '\n';
            for (int i = 1; i <= n; i++) {
                cout << A << " \n"[i == n];
            }              
        }
        return;   
    }
    
    vector <vector<int>> part;
    vector <int> t, bel(n + 1, -1);
    function <void(int)> dfs = [&] (int u) {
        bel[u] = sz(part);
        t.push_back(u);
        for (auto v : G[u]) {
            if (bel[v] == -1) {
                dfs(v);
            }
        }
    };
    
    for (int i = 1; i <= n; i++) if (bel[i] == -1) {
        t.clear();
        dfs(i);
        part.push_back(t);
    }
    
    vector <int> col(n + 1);
    auto bfs = [&] (int u) {
        int res = 0;
        col[u] = 1;
        queue <int> q;
        q.push(u);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            res = max(res, col[u]);
            for (auto v : G[u]) {
                if (!col[v]) {
                    col[v] = col[u] + 1;
                    q.push(v);
                } else if (col[u] == col[v]) {
                    return -1;
                }
            }
        }
        return res;
    };
    
    int sum = 0;   
    for (int i = 0; i < sz(part); i++) {
        int node, dis = 0;
        for (auto u : part[i]) {
            for (auto it : part[i]) col[it] = 0;
            int tmp = bfs(u);
            if (tmp == -1) continue;
            if (tmp > dis) {
                dis = tmp;
                node = u;
            }
        }
        if (dis == 0) {
            cout << "No" << '\n';
            return;
        }
        for (auto it : part[i]) col[it] = 0;
        bfs(node);
        for (auto u : part[i]) {
            if (sum + col[u] > k) {
                col[u] = k - ((sum + col[u] - k) & 1);
            } else col[u] += sum;
        }
        sum += dis;
    }
    if (sum < k) {
        cout << "No" << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        col[i] += A - 1;
    }
    cout << "Yes" << '\n';
    for (int i = 1; i <= n; i++) {
        cout << col[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
