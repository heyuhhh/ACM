#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
using namespace std;

const int MAX_N = 1e6;
string maze[1001];
vector<int> g[MAX_N];
int depth[MAX_N];
int eulerdepth[2 * MAX_N];
int eulervisit[MAX_N];

void addEdge(int a, int b)
{
	g[a].push_back(b);
	g[b].push_back(a);
}

void computeRanks(int node, int &idx, int prev)
{
	eulerdepth[idx] = depth[node];
	if (eulervisit[node] == -1)
	{
		eulervisit[node] = idx;
		for (int neigh : g[node])
		{
			if (neigh == prev)
				continue;
			depth[neigh] = depth[node] + 1;
			computeRanks(neigh, ++idx, node);
			eulerdepth[++idx] = depth[node];
		}
	}
}

struct Node {int l,r,val;};
Node st[5000000];

int buildSegTree(int pos, int l, int r)
{
	st[pos].l = l;
	st[pos].r = r;
	if (l == r)
		return st[pos].val = eulerdepth[l];
	int m = (l+r)/2;
	return st[pos].val = min(buildSegTree(2*pos+1, l, m), buildSegTree(2*pos+2, m+1, r));
}

int minSegTree(int pos, int l, int r)
{
	if (l > st[pos].r || r < st[pos].l)
		return numeric_limits<int>::max();
	if (l <= st[pos].l && r >= st[pos].r)
		return st[pos].val;
	return min(minSegTree(2*pos+1, l, r), minSegTree(2*pos+2, l, r));
}

int main()
{
	int l,w; cin >> l >> w;
	getline(cin, maze[0]);
	for (int i = 0; i < l+1; ++i)
		getline(cin, maze[i]);
		
	for (int i = 0; i < l; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			int id = i * w + j;
			int x = i + 1;
			int y = j * 2 + 1;
			if (maze[x][y] != '_' && i + 1 != l)
				addEdge(id,id+w);
			if (maze[x][y+1] != '|' && j + 1 != w)
				addEdge(id,id+1);
		}
	}
	memset(eulervisit, -1, MAX_N * sizeof(*eulervisit));
	int idx = 0;
	computeRanks(0,idx,-1);
	buildSegTree(0,0,2*l*w-2);
	int m; cin >> m;
	long long res = 0;
	int curPos = -1;
	for (int i = 0; i < m; ++i)
	{
		int x, y; cin >> y >> x;
		int nextPos = (--y) * w + (--x);
		if (i != 0)
		{
			int src = eulervisit[curPos];
			int dst = eulervisit[nextPos];
			int lcaDepth = minSegTree(0,min(src,dst),max(src,dst));
			int len = depth[curPos] + depth[nextPos] - 2 * lcaDepth;
			res += depth[curPos] + depth[nextPos] - 2 * lcaDepth;
		}
		curPos = nextPos;
	}
	cout << res << endl;
}
