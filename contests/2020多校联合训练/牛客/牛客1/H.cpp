// Author : heyuhhh
// Created Time : 2020/07/12 14:24:44
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 100 + 5, M = 200 + 5;

#define INF 0x3f3f3f3f
struct E {
    int from, to, cp, v;
    E() {}
    E(int f, int t, int cp, int v) : from(f), to(t), cp(cp), v(v) {}
};
int f[M];
struct MCMF {
    int n, m, s, t;
    vector<E> edges;
    vector<int> G[N];
    bool inq[N];
    int d[N], p[N], a[M];

    void init(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t;
        for(int i = 0; i <= n; i++) G[i].clear();
        edges.clear(); m = 0;
    }

    void addedge(int from, int to, int cap, int cost) {
        edges.emplace_back(from, to, cap, cost);
        edges.emplace_back(to, from, 0, -cost);
        G[from].push_back(m++);
        G[to].push_back(m++);
    }

    bool BellmanFord(int &flow, int &cost) {
        for(int i = 0; i <= n; i++) d[i] = INF;
        memset(inq, 0, sizeof inq);
        d[s] = 0, a[s] = INF, inq[s] = true;
        queue<int> Q; Q.push(s);
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            inq[u] = false;
            for (int& idx: G[u]) {
                E &e = edges[idx];
                if (e.cp && d[e.to] > d[u] + e.v) {
                    d[e.to] = d[u] + e.v;
                    p[e.to] = idx;
                    a[e.to] = min(a[u], e.cp);
                    if (!inq[e.to]) {
                        Q.push(e.to);
                        inq[e.to] = true;
                    }
                }
            }
        }
        if (d[t] == INF) return false;
        flow += a[t];
        cost += a[t] * d[t];
        int u = t;
        while (u != s) {
            edges[p[u]].cp -= a[t];
            edges[p[u] ^ 1].cp += a[t];
            u = edges[p[u]].from;
        }
        return true;
    }

    void go(int& flow) {
        flow = 0;
        int cost = 0;
        while (BellmanFord(flow, cost)) {
            f[flow] = f[flow - 1] + cost;
            cost = 0;
        };
    }
} MM;

int n, m;

void run() {
    MM.init(n, 1, n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        MM.addedge(u, v, 1, w);
    }
    int npath;
    MM.go(npath);
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        if (u == 0) {
            cout << "NaN" << '\n';
            continue;
        }
        int need = (v + u - 1) / u;
        if (need > npath) {
            cout << "NaN" << '\n';
        } else {
            assert(u > 0 && v >= u);
            assert(need > 0);
            ll fz = 1ll * f[need - 1] * u + 1ll * (f[need] - f[need - 1]) * (v - (need - 1) * u);
            ll fm = v;
            ll g = __gcd(fz, fm);
            assert(g > 0);
            fz /= g, fm /= g;
            cout << fz << "/" << fm << '\n';
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while (cin >> n >> m) run();
    return 0;
}