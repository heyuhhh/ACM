#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int n, k;
#define INF 0x3f3f3f3f
template <class T>
struct Dinic{
    struct Edge{
        int v, next;
        T flow;
        Edge(){}
        Edge(int v, int next, T flow) : v(v), next(next), flow(flow) {}
    }e[N << 1];
    int head[N], tot;
    int dep[N];
    void init() {
        memset(head, -1, sizeof(head)); tot = 0;
    }
    void adde(int u, int v, T w, T rw = 0) {
        e[tot] = Edge(v, head[u], w);
        head[u] = tot++;
        e[tot] = Edge(u, head[v], rw);
        head[v] = tot++;
    }
    bool BFS(int _S, int _T) {
        memset(dep, 0, sizeof(dep));
        queue <int> q; q.push(_S); dep[_S] = 1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = head[u]; ~i; i = e[i].next) {
                int v = e[i].v;
                if(!dep[v] && e[i].flow > 0) {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return dep[_T] != 0;
    }
    T dfs(int _S, int _T, T a) {
        T flow = 0, f;
        if(_S == _T || a == 0) return a;
        for(int i = head[_S]; ~i; i = e[i].next) {
            int v = e[i].v;
            if(dep[v] != dep[_S] + 1) continue;
            f = dfs(v, _T, min(a, e[i].flow));
            if(f) {
                e[i].flow -= f;
                e[i ^ 1].flow += f;
                flow += f;
                a -= f;
                if(a == 0) break;
            }
        }
        if(!flow) dep[_S] = -1;
        return flow;
    }
    T dinic(int _S, int _T) {
        T max_flow = 0;
        while(BFS(_S, _T)) max_flow += dfs(_S, _T, INF);
        return max_flow;
    }
    bool ok(int p) {
		for (int i = head[p]; ~i; i = e[i].next) {
			int f = e[i].flow;
			if (f == 0) return true;
		}
		return false;
    }
};

Dinic<int> solver;

void run() {
	cin >> n >> k;
	solver.init();
	int cur = 2 * n;
	int S = N - 2, T = N - 1;
	for (int i = 0; i < n; i++) {
		solver.adde(2 * i, cur, 1);
		solver.adde(2 * i + 1, cur, 1);
		solver.adde(cur, T, 1);
		cur++;
	}
	vector<vector<pair<int, char>>> V(k);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 3; j++) {
			int p;
			char c;
			cin >> p >> c;
			--p;
			V[i].emplace_back(p, c);
			if (c == 'B') solver.adde(cur, 2 * p, 1);
			else solver.adde(cur, 2 * p + 1, 1);
		}
		solver.adde(S, cur, 2);
		++cur;
	}
	int f = solver.dinic(S, T);
	vector<char> ans(n);
	for (int i = 0; i < n; i++) {
		if (solver.ok(2 * i)) {
			ans[i] = 'B';
		} else {
			ans[i] = 'R';
		}
	}
	for (auto it : ans) {
		cout << it;
	} cout << '\n';
	bool flag = true;
	for (int i = 0; i < k; i++) {
		int cnt = 0;
		for (auto it : V[i]) {
			int p = it.first;
			char c = it.second;
			if (ans[p] == c) ++cnt;
		}
		if (cnt < 2) {
			flag = false;
		}
	}
	if (flag) {
		for (auto it : ans) {
			cout << it;
		}
		cout << '\n';
	} else {
		cout << -1 << '\n';
	}
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	run();	
	return 0;
}
