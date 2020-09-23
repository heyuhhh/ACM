#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const int MAX_C = 500*500;
const int MAX_Q = 1e5;
int rnk[MAX_C];
int par[MAX_C];
int res[MAX_Q];
set<int> routes[MAX_C];
int cells_x[MAX_C];
int cells_y[MAX_C];
int cells_h[MAX_C];

int root(int a)
{
	if (a != par[a])
		par[a] = root(par[a]);
	return par[a];
}

void unite(int a, int b)
{
	int ra = root(a);
	int rb = root(b);
	if (ra == rb)
		return;
	if (rnk[ra] < rnk[rb])
		swap(ra,rb);
	if (rnk[ra] == rnk[rb])
		rnk[ra]++;
	par[rb] = ra;	
	for (int k : routes[rb])
	{
		if (routes[ra].count(k))
		{
			res[k] = max(cells_h[a],cells_h[b]);
			routes[ra].erase(k);
		}
		else
			routes[ra].insert(k);
	}
}

int main()
{
	int m,n,q; 
	scanf("%d %d %d", &m, &n, &q);
	vector<pair<int,int>> cells;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int id = i * n + j;
			cells_x[id] = i;
			cells_y[id] = j;
			scanf("%d", cells_h + id);
			cells.push_back(make_pair(cells_h[id],id));
		}
	}
	sort(cells.begin(), cells.end());

	for (int i = 0; i < q; ++i)
	{
		int x1,y1,x2,y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1--; y1--; x2--; y2--;
		int id1 = x1 * n + y1;
		int id2 = x2 * n + y2;
		if (id1 == id2)
			res[i] = cells_h[id1];
		else
		{
			routes[id1].insert(i);
			routes[id2].insert(i);
		}
	}
	for (int i = 0; i < m*n; i++)
		par[i] = i;

	for (const auto &p : cells)
	{
		int h = p.first;
		int x = p.second / n;
		int y = p.second % n;
		int shift_x[4] = {-1,1,0,0};
		int shift_y[4] = {0,0,-1,1};
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + shift_x[i];
			int ny = y + shift_y[i];
			if (nx < 0 || nx >= m || ny < 0 || ny >= n)
				continue;
			int neigh = nx * n + ny;
			if (cells_h[neigh] <= h)
				unite(p.second, neigh);			
		} 
	}
	for (int i = 0; i < q; ++i)
		printf("%d\n", res[i]);
}
