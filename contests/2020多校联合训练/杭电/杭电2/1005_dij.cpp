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
const int N = 50000 + 5, M = 100000 + 5;

ll F[N];
int T;
struct edge {
	int to, capacity;
    ll cost;
    int rev;
	edge() {}
	edge(int to, int _capacity, ll _cost, int _rev) :to(to), capacity(_capacity), cost(_cost), rev(_rev) {}
};
struct Min_Cost_Max_Flow {
	int V, PreV[N << 1], PreE[N << 1];
    ll dis[N << 1], H[N << 1];
	vector<edge> G[N << 1];
	void Init(int n) {
		V = n;
		for (int i = 0; i <= V; ++i)G[i].clear();
	}
	void Add_Edge(int from, int to, int cap, int cost) {
		G[from].push_back(edge(to, cap, cost, G[to].size()));
		G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
	}
//flow是自己传进去的变量，就是最后的最大流，返回的是最小费用，f=INF
	int Min_cost_max_flow(int s, int t, int f, int& flow) {
		ll res = 0; fill(H, H + 1 + V, 0);
		while (f) {
			priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > q;
			fill(dis, dis + 1 + V, 6e18);
			dis[s] = 0; q.push(pair<ll, int>(0, s));
			while (!q.empty()) {
				pair<ll, int> now = q.top(); q.pop();
				int v = now.second;
				if (dis[v] < now.first)continue;
				for (int i = 0; i < G[v].size(); ++i) {
					edge& e = G[v][i];
					if (e.capacity > 0 && dis[e.to] > dis[v] + e.cost + H[v] - H[e.to]) {
						dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
						PreV[e.to] = v;
						PreE[e.to] = i;
						q.push(pair<ll, int>(dis[e.to], e.to));
					}
				}
			}
			if (dis[t] == 6e18)break;
			for (int i = 0; i <= V; ++i)H[i] += dis[i];
			int d = f;
			for (int v = t; v != s; v = PreV[v])d = min(d, G[PreV[v]][PreE[v]].capacity);
			f -= d; flow += d; res += 1ll*d*H[t];
			for (int v = t; v != s; v = PreV[v]) {
				edge& e = G[PreV[v]][PreE[v]];
				e.capacity -= d;
				G[v][e.rev].capacity += d;
			}
            F[++T] = res;
		}
		return res;
	}
}sol;

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
    sol.Init(tot + 1);
    for (int i = 1; i <= n; i++) {
        sol.Add_Edge(0, i, 1, 0);
    }
    for (auto& it : mp) {
        sol.Add_Edge(it.se, tot + 1, 1, 0);
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] >= 0) {
            for (int j = 1; j <= min(m, n + 1); j++) {
                sol.Add_Edge(i, mp[j], 1, 1ll * a[i] * j * j + 1ll * b[i] * j + c[i]);
            }
        } else {
            int t = - b[i] / (2 * a[i]);
            for (int j = max(t - n, 1); j <= min(m, t + n); j++) {
                sol.Add_Edge(i, mp[j], 1, 1ll * a[i] * j * j + 1ll * b[i] * j + c[i]);
            }
        }
    }
    int flow;
    T = 0;
    sol.Min_cost_max_flow(0, tot + 1, INF, flow);
    for (int i = 1; i <= T; i++) {
        cout << F[i] << " \n"[i == n];
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