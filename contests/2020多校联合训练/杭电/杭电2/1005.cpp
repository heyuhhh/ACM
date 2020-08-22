// Author : heyuhhh
// Created Time : 2020/07/23 22:39:10
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
const int N = 5000 + 5, M = 50000 + 5;

struct E {
    int from, to, cp;
    ll v;
    E() {}
    E(int f, int t, int cp, ll v) : from(f), to(t), cp(cp), v(v) {}
};

ll f[N];

struct MCMF {
    int n, m, s, t;
    vector<E> edges;
    vector<int> G[N];
    bool inq[N];
    ll d[N];
    int p[N], a[M];

    void init(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t;
        for(int i = 0; i <= n; i++) G[i].clear();
        edges.clear(); m = 0;
    }

    void addedge(int from, int to, int cap, ll cost) {
        edges.emplace_back(from, to, cap, cost);
        edges.emplace_back(to, from, 0, -cost);
        G[from].push_back(m++);
        G[to].push_back(m++);
    }

    bool BellmanFord(int &flow, ll &cost) {
        for(int i = 0; i <= n; i++) d[i] = 6e18;
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
        if (d[t] == 6e18) return false;
        flow += a[t];
        cost += 1ll * a[t] * d[t];
        int u = t;
        while (u != s) {
            edges[p[u]].cp -= a[t];
            edges[p[u] ^ 1].cp += a[t];
            u = edges[p[u]].from;
        }
        return true;
    }

    ll go() {
        int flow = 0;
        ll cost = 0;
        int t = 0;
        while (BellmanFord(flow, cost)) {
            f[++t] = cost;
        }
        return cost;
    }
} MM;

int a[N], b[N];
ll c[N];
int n, m;

void run() {
    map<int, int> mp;
    cin >> n >> m;
    int tot = n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        if (b[i] >= 0) {
            for (int j = 1; j <= min(m, n + 1); j++) {
                if (mp.find(j) == mp.end()) {
                    mp[j] = ++tot;
                }
            }
        } else {
            int t = - b[i] / (2 * a[i]);
            for (int j = max(t - n, 1); j <= min(m, t + n); j++) {
                if (mp.find(j) == mp.end()) {
                    mp[j] = ++tot;
                }
            }
        }
    }
    MM.init(tot + 1, 0, tot + 1);
    for (int i = 1; i <= n; i++) {
        MM.addedge(0, i, 1, 0);
    }
    for (auto& it : mp) {
        MM.addedge(it.se, tot + 1, 1, 0);
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] >= 0) {
            for (int j = 1; j <= min(m, n + 1); j++) {
                MM.addedge(i, mp[j], 1, 1ll * a[i] * j * j + 1ll * b[i] * j + c[i]);
            }
        } else {
            int t = - b[i] / (2 * a[i]);
            for (int j = max(t - n, 1); j <= min(m, t + n); j++) {
                MM.addedge(i, mp[j], 1, 1ll * a[i] * j * j + 1ll * b[i] * j + c[i]);
            }
        }
    }
    MM.go();
    for (int i = 1; i <= n; i++) {
        cout << f[i] << " \n"[i == n];
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}