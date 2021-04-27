#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
double MMM = 1e-6;

int n, m;
int val[1010];
struct edge{
	int to, next, w;
}e[20010];
int head[2010], tot;
void add(int x, int y, int w) {
	e[++tot] = (edge){y, head[x], w};
	head[x] = tot;
}
int s;

int u, v, w;

int vis[2010], cnt[2010];
double dis[2010];
bool spfa(double T) {
	for(int i = 0; i <= n; i++) vis[i] = cnt[i] = 0, dis[i] = 0x3f3f3f3f;
	queue<int> q;
	dis[s] = 0;
	vis[s] = cnt[s] = 1;
	q.push(s);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		for(int i = head[now], to = e[i].to; i; i = e[i].next, to = e[i].to) {
			double tmp = e[i].w;
			if(i > n + 1) tmp += T;
			if(dis[to] > dis[now] + tmp) {
				dis[to] = dis[now] + tmp;
				if(!vis[to]){
					q.push(to);
					vis[to] = 1;
					cnt[to]++;
					if(cnt[to] > n + 1) return false;
				}
			}
		}
		vis[now] = 0;
	}
	return true;
}


void run() {
	while(cin >> n >> m) {
		int flag = 0;
		tot = head[0] = head[n + 1] = 0;
		
		for(int i = 1; i <= n; i++) {
			head[i] = 0;
			char ch;
			do {
				ch = cin.peek();
				if(ch>' ') break;
				cin.ignore();
			} while(1);
			if(ch == '?') cin.ignore(), val[i] = 1e6, flag = 1;
			else cin >> val[i];
		}
		s = n + 1;
		for(int i = 0; i <= n; i++) add(s, i, 0);
		double l = 0, r = 1e9;	
		for(int i = 1; i <= m; i++) {
			cin >> u >> v >> w;
			if(val[u] == 1e6 && val[v] == 1e6) add(v, u, -w);
			else if(val[u] == 1e6 && val[v] != 1e6) add(0, u, val[v] - w);
			else if(val[u] != 1e6 && val[v] == 1e6) add(v, 0, -val[u] - w);
		 	else l = max(l, (double)val[u] - val[v] + w);
		}
		if(m == 0) {
			cout << 0 << endl;
			for(int i = 1; i <= n; i++) cout << val[i] << ' ';
			cout << '\n';
			continue;
		}
		if(!flag) {
			cout << l << endl;
			for(int i = 1; i <= n; i++) cout << val[i] << ' ';
			cout << '\n';
			continue;
		}
		while(r - l >= MMM) {
			double mid = (l + r) / 2.0;
			if(spfa(mid)) r = mid;
			else l = mid;
		}
		cout << l << endl;
		for(int i = 1; i <= n; i++) if(val[i] != 1e6) cout << val[i] << " ";
		else cout << dis[i] - dis[0] << " ";
		cout << '\n';
	}
		

}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
//	int T; cin >> T; while (T--)
	run();
	return 0;
}

