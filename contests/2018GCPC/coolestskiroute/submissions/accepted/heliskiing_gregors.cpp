#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
const int MAX_N = 1e3+1;

vector<pair<int,int>> g[MAX_N];
int cnt[MAX_N];
int topo[MAX_N];
int d[MAX_N];
queue<int> q;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		x--; y--;
		g[x].push_back(make_pair(y,w));
		cnt[y]++;
	}
	for (int i = 0; i < n; ++i)
	{
		if (cnt[i] == 0)
			q.push(i);
		g[i].push_back(make_pair(n,0));
		cnt[n]++;
	}
	int idx = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		topo[idx++] = x;
		for (auto &p : g[x])
			if (--cnt[p.first] == 0)
				q.push(p.first);
	}
	for (int i = 0; i <= n; ++i)
	{
		int k = topo[i];
		for (auto &p : g[k])
			if (d[k] - p.second < d[p.first])
				d[p.first] = d[k] - p.second;
	}
	printf("%d\n", -d[n]);
}

