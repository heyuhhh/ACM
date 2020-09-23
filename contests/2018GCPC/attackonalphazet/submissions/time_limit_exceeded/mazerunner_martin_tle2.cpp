#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <cstdio>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <functional>
#include <bitset>
#include <cctype>
#include <cassert>
#include <cstdint>
using namespace std;
#ifdef DEBUG
#define db(a) (cout << (#a) << " = " << (a) << endl)
#else
#define db(a)
#endif
using ll = int64_t;

/*
 * 	Naive LCA by iterating over the dijkstra paths.
 */

int L, W;
vector<int> M[1024][1024];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
vector<pair<int,int>> G;
int dist[1024][1024];
pair<int,int> path[1024][1024];

struct vertex
{
  vertex(const pair<int,int>& _v, const int _w) : v(_v), w(_w) {}
  pair<int,int> v;
  int w;
};

bool operator<(const vertex& a, const vertex& b)
{
  if(a.w == b.w && a.v.first == b.v.first) return a.v.second > b.v.second;
  if(a.w == b.w) return a.v.first > b.v.first;
  return a.w > b.w;
}

void dijkstra(pair<int,int> start)
{
	for(int i=0;i<L;i++) for(int j=0;j<W;j++) dist[i][j] = -1;
	dist[start.second][start.first] = 0;
	priority_queue<vertex> q;
	q.push(vertex(start, 0));
	path[start.second][start.first] = start;
	while(!q.empty())
	{
		auto pos = q.top();
		q.pop();
		if(pos.w > dist[pos.v.second][pos.v.first]) continue;
		for(auto dir : M[pos.v.second][pos.v.first])
		{
			int y = pos.v.second + dy[dir];
			int x = pos.v.first + dx[dir];
			int newd = dist[pos.v.second][pos.v.first] + 1;
			if(dist[y][x] < 0 || newd < dist[y][x])
			{
				dist[y][x] = newd;
				path[y][x] = pos.v;
				q.push(vertex({x,y}, newd));
			}
		}
	}
}

pair<int,int> zero;
struct piihash
{
	size_t operator()(const std::pair<int, int>& p) const
  {
    return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
  }
};


int dis(const pair<int,int>& start, const pair<int,int>& end)
{
	unordered_set<pair<int,int>, piihash> S;	
	auto pos = start;
	S.insert(pos);
	while(pos != zero)
	{
		pos = path[pos.second][pos.first];
		S.insert(pos);
	}
	pos = end;
	while(true)
	{
		if(S.count(pos) > 0) return dist[start.second][start.first] + dist[end.second][end.first] - 2 * dist[pos.second][pos.first];
		pos = path[pos.second][pos.first];
	}
	return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

	cin >> L >> W;

	string s;
	getline(cin, s);
	getline(cin, s);	
	char b,c;
	for(int y=0;y<L;y++) 
	{
		getline(cin, s);
		for(int x=0;x<W;x++)
		{
			b = s[2*x+1];
			c = s[2*x+2];	
			if(b == ' ')
			{
				M[y][x].push_back(2);
				M[y+1][x].push_back(0);	
			}
			if(c == ' ')
			{
				M[y][x].push_back(1);
				M[y][x+1].push_back(3);
			}
		}
	}
	int N;
	cin>>N;
	for(int m=0;m<N;m++)
	{
		int x,y;
		cin>>y>>x;
		G.push_back({--x, --y});
	}

	ll erg = 0;	
	for(int y=0;y<L;y++) for(int x=0;x<W;x++) if(M[y][x].size() == 1) zero = pair<int,int>(x,y);
	dijkstra(zero);
	for(size_t i=1;i<G.size();i++) erg += dis(G[i-1], G[i]);
	cout << erg << "\n";

  return 0;
}
