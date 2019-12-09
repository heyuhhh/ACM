//author Forsaken
#define Hello the_cruel_world!
#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<cmath>
#include<climits>
#include<deque>
#include<functional>
#include<numeric>
#define max(x,y) ((x) > (y) ? (x) : (y))
#define min(x,y) ((x) < (y) ? (x) : (y))
#define lowbit(x) ((x) & (-(x)))
#define FRIN freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\1.in", "r", stdin)
#define FROUT freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\1.out", "w", stdout)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define outd(x) printf("%d\n", x)
#define outld(x) printf("%lld\n", x)
#define memset0(arr) memset(arr, 0, sizeof(arr))
#define il inline
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int maxn = 1e4;
const int INF = 0x7fffffff;
const int mod = 1e9 + 7;
const double eps = 1e-7;
const double Pi = acos(-1.0);
il int read_int() {
	char c;
	int ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
il ll read_ll() {
	char c;
	ll ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
il ll quick_pow(ll base, ll index) {
	ll res = 1;
	while (index) {
		if (index & 1)res = res * base % mod;
		base = base * base % mod;
		index >>= 1;
	}
	return res;
}
struct edge {
	int to, capacity, cost, rev;
	edge() {}
	edge(int to, int _capacity, int _cost, int _rev) :to(to), capacity(_capacity), cost(_cost), rev(_rev) {}
};
struct Min_Cost_Max_Flow {
	int V, H[maxn + 5], dis[maxn + 5], PreV[maxn + 5], PreE[maxn + 5];
	vector<edge> G[maxn + 5];
	//调用前初始化
	void Init(int n) {
		V = n;
		for (int i = 0; i <= V; ++i)G[i].clear();
	}
	//加边
	void Add_Edge(int from, int to, int cap, int cost) {
		G[from].push_back(edge(to, cap, cost, G[to].size()));
		G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
	}
	//flow是自己传进去的变量，就是最后的最大流，返回的是最小费用
	int Min_cost_max_flow(int s, int t, int f, int& flow) {
		int res = 0; fill(H, H + 1 + V, 0);
		while (f) {
			priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
			fill(dis, dis + 1 + V, INF);
			dis[s] = 0; q.push(pair<int, int>(0, s));
			while (!q.empty()) {
				pair<int, int> now = q.top(); q.pop();
				int v = now.second;
				if (dis[v] < now.first)continue;
				for (int i = 0; i < G[v].size(); ++i) {
					edge& e = G[v][i];
					if (e.capacity > 0 && dis[e.to] > dis[v] + e.cost + H[v] - H[e.to]) {
						dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
						PreV[e.to] = v;
						PreE[e.to] = i;
						q.push(pair<int, int>(dis[e.to], e.to));
					}
				}
			}
			if (dis[t] == INF)break;
			for (int i = 0; i <= V; ++i)H[i] += dis[i];
			int d = f;
			for (int v = t; v != s; v = PreV[v])d = min(d, G[PreV[v]][PreE[v]].capacity);
			f -= d; flow += d; res += d*H[t];
			for (int v = t; v != s; v = PreV[v]) {
				edge& e = G[PreV[v]][PreE[v]];
				e.capacity -= d;
				G[v][e.rev].capacity += d;
			}
		}
		return res;
	}
	int Max_cost_max_flow(int s, int t, int f, int& flow) {
		int res = 0;
		fill(H, H + 1 + V, 0);
		while (f) {
			priority_queue <pair<int, int>> q;
			fill(dis, dis + 1 + V, -INF);
			dis[s] = 0;
			q.push(pair<int, int>(0, s));
			while (!q.empty()) {
				pair<int, int> now = q.top(); q.pop();
				int v = now.second;
				if (dis[v] > now.first)continue;
				for (int i = 0; i < G[v].size(); ++i) {
					edge& e = G[v][i];
					if (e.capacity > 0 && dis[e.to] < dis[v] + e.cost + H[v] - H[e.to]) {
						dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
						PreV[e.to] = v;
						PreE[e.to] = i;
						q.push(pair<int, int>(dis[e.to], e.to));
					}
				}
			}
			if (dis[t] == -INF)break;
			for (int i = 0; i <= V; ++i)H[i] += dis[i];
			int d = f;
			for (int v = t; v != s; v = PreV[v])d = min(d, G[PreV[v]][PreE[v]].capacity);
			f -= d; flow += d;
			res += d*H[t];
			for (int v = t; v != s; v = PreV[v]) {
				edge& e = G[PreV[v]][PreE[v]];
				e.capacity -= d;
				G[v][e.rev].capacity += d;
			}
		}
		return res;
	}
};
int n, k, s1, s2, t, flow, arr[maxn + 5];
Min_Cost_Max_Flow MCMF;
int main()
{
	for (int kase = read_int(); kase > 0; --kase) {
		n = read_int(), k = read_int();
		s1 = 0, s2 = 2 * n + 1, t = 2 * n + 2;
		MCMF.Init(t);
		MCMF.Add_Edge(s1, s2, k, 0);
		for (int i = 1; i <= n; ++i) {
			arr[i] = read_int();
			MCMF.Add_Edge(i, i + n, 1, -arr[i]);
		}
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j) {
				if (arr[i] <= arr[j])MCMF.Add_Edge(i + n, j, 1, 0);
			}
		for (int i = 1; i <= n; ++i) {
			MCMF.Add_Edge(s2, i, 1, 0);
			MCMF.Add_Edge(i + n, t, 1, 0);
		}
		cout << -MCMF.Min_cost_max_flow(s1, t, INF, flow) << endl;
	}
	return 0;
}
