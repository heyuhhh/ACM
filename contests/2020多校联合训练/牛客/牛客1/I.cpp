// Author : heyuhhh
// Created Time : 2020/07/12 20:50:24
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 500 + 5, M = 100 + 5;

int n, m;
int d[N];

struct mf {
    // Time complexity: O(n^3)
    // 1-based Vertex index
    // match[x]: vertex matched with x
    // N: numbers of vertex
    int vis[N], par[N], orig[N], match[N], aux[N], t, n;
    vector<int> conn[N];
    queue<int> Q;
    void add_edge(int u, int v) {
        conn[u].push_back(v);
        conn[v].push_back(u);
    }
    void init(int _n) {
        n = _n;
        t = 0;
        for (int i = 0; i <= n; ++i) {
            conn[i].clear();
            match[i] = aux[i] = par[i] = 0;
        }
    }
    void augment(int u, int v) {
        int pv = v, nv;
        do {
            pv = par[v];
            nv = match[pv];
            match[v] = pv;
            match[pv] = v;
            v = nv;
        } while (u != pv);
    }
    int lca(int v, int w) {
        ++t;
        while (true) {
            if (v) {
                if (aux[v] == t) return v;
                aux[v] = t;
                v = orig[par[match[v]]];
            }
            swap(v, w);
        }
    }
    void blossom(int v, int w, int a) {
        while (orig[v] != a) {
            par[v] = w;
            w = match[v];
            if (vis[w] == 1) Q.push(w), vis[w] = 0;
            orig[v] = orig[w] = a;
            v = par[w];
        }
    }
    bool bfs(int u) {
        fill(vis + 1, vis + 1 + n, -1);
        iota(orig + 1, orig + n + 1, 1);
        Q = queue<int>();
        Q.push(u);
        vis[u] = 0;
        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            for (int x : conn[v]) {
                if (vis[x] == -1) {
                    par[x] = v;
                    vis[x] = 1;
                    if (!match[x]) return augment(u, x), true;
                    Q.push(match[x]);
                    vis[match[x]] = 0;
                } else if (vis[x] == 0 && orig[v] != orig[x]) {
                    int a = lca(orig[v], orig[x]);
                    blossom(x, v, a);
                    blossom(v, x, a);
                }
            }
        }
        return false;
    }
    int Match() {
        int ans = 0;
        // find random matching (not necessary, constant improvement)
        vector<int> V(n - 1);
        iota(V.begin(), V.end(), 1);
        shuffle(V.begin(), V.end(), mt19937(61471));
        for (auto x : V)
            if (!match[x]) {
                for (auto y : conn[x])
                if (!match[y]) {
                    match[x] = y, match[y] = x;
                    ++ans;
                    break;
                }
            }
        for (int i = 1; i <= n; ++i)
            if (!match[i] && bfs(i)) ++ans;
        return ans;
    }
} mf;

void run() {
    mf.init(500);
    int deg = 0;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        deg += d[i];
    }
    int nxt = 150;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        mf.add_edge(nxt, nxt + 1);
        for (int j = 0; j < d[u]; j++) {
            mf.add_edge(2 * u + j, nxt);
        }
        for (int j = 0; j < d[v]; j++) {
            mf.add_edge(nxt + 1, 2 * v + j);
        }
        nxt += 2;
    }
    int Max = mf.Match();
    if (deg == 2 * Max - 2 * m) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while (cin >> n >> m) run();
    return 0;
}