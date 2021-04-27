#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e4 + 5;
#define INF 0x3f3f3f3f

int n, k;

vector<int> G[N], rG[N], vs;
int used[N], bel[N];

void adde(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
}

void dfs(int v) {
    used[v] = true;
    for(int u: G[v]) {
        if(!used[u])
            dfs(u);
    }
    vs.push_back(v);
}

void rdfs(int v, int k) {
    used[v] = true;
    bel[v] = k;
    for(int u: rG[v])
        if(!used[u])
            rdfs(u, k);
}

int scc() {
    memset(used, 0, sizeof(used));
    vs.clear();
    for(int v = 0; v < 2 * n; ++v)
        if(!used[v]) dfs(v);
    memset(used, 0, sizeof(used));
    int k = 0;
    for(int i = (int) vs.size() - 1; i >= 0; --i)
        if(!used[vs[i]]) rdfs(vs[i], k++);
    return k;
}

int trans(int i, char c, int op) {
	if (c == 'B') {
	 	if (op == 0) return 2 * i;
		else return 2 * i + 1;
	} else {
		if (op == 0) return 2 * i + 1;
		return 2 * i;
	}
}

void work(vector<pair<int, char>>& V) {
	int p1 = V[0].first, p2 = V[1].first, p3 = V[2].first;
	char c1 = V[0].second, c2 = V[1].second, c3 = V[2].second;
	
	adde(trans(p1, c1, 1), trans(p2, c2, 0));
	adde(trans(p1, c1, 1), trans(p3, c3, 0));
	
	adde(trans(p2, c2, 1), trans(p1, c1, 0));
	adde(trans(p2, c2, 1), trans(p3, c3, 0));
	
	adde(trans(p3, c3, 1), trans(p1, c1, 0));
	adde(trans(p3, c3, 1), trans(p2, c2, 0));
}



void run() {
	cin >> n >> k;
	vector<vector<pair<int, char>>> V(k);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 3; j++) {
			int p;
			char c;
			cin >> p >> c;
			--p;
			V[i].emplace_back(p, c);
		}
		work(V[i]);
	}
	scc();
	for (int i = 0; i < n; i++) {
		if (bel[2 * i] == bel[2 * i + 1]) {
			cout << -1 << '\n';
			return;
		}
	}
	for (int i = 0; i < n; i++) {
		if (bel[2 * i] > bel[2 * i + 1]) {
			cout << 'B';
		} else {
			cout << 'R';
		}
	}
	cout << '\n';
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
