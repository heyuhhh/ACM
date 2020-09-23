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

int M,N,Q;
int G[512][512];



struct uf
{
	constexpr static int MAX_COUNT = 512*512;
	int array[MAX_COUNT];

	void makeset(int i)
	{
		array[i]=-1;
	}

	int find(int i)
	{
		if(array[i]==i) return -(MAX_COUNT+1);
		int in=i;	
		int j=array[i];
		while(j>=0) {i=j;j=array[j];}
		int s = array[i];
		j=in;
		while(j>=0) {j=array[j];array[in]=i;in=j;}
		array[i] = s;
		return i;
	}

	void uni(int i,int j)
	{
		if(i==j) return;
		if(i<(-MAX_COUNT)||j<(-MAX_COUNT)) return;
		if(array[i]>array[j]) {array[j]+=array[i];array[i]=j;}
		else {array[i]+=array[j];array[j]=i;}		
	}
} U;

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
  return a.w < b.w;
}

struct query
{
	int sx, sy;
	int ex, ey;
	int erg;
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
	cin>>M>>N>>Q;
	vector<vertex> V;
	for(int i=0;i<M;i++) for(int j=0;j<N;j++)
	{
		cin>>G[i][j];
		V.push_back(vertex({i, j}, G[i][j]));
	}
	sort(begin(V), end(V));

	vector<query> queries;
	for(int i=0;i<Q;i++)
	{
		query q;
		cin >> q.sx >> q.sy >> q.ex >> q.ey;
		q.sx--; q.sy--; q.ex--; q.ey--;
		if(q.sx == q.ex && q.sy == q.ey) q.erg = G[q.sx][q.sy];	
		else q.erg = -1;
		queries.push_back(q);
	}
		
	for(int i=0;i<M;i++) for(int j=0;j<N;j++) U.makeset(i+j*M);
	for(const auto& v : V)
	{
		static const int dx[] = {0,0,1,-1};
		static const int dy[] = {1,-1,0,0};
		for(int i=0;i<4;i++)
		{
			int x = v.v.first + dx[i];
			int y = v.v.second + dy[i];
			if(x < 0 || y < 0 || x >= M || y >=N) continue;
			if(G[x][y] <= v.w) U.uni(U.find(x+y*M), U.find(v.v.first+v.v.second*M));
		}
		
		for(auto& q : queries)
		{
			if(q.erg == -1 && U.find(q.sx+q.sy*M) == U.find(q.ex+q.ey*M)) q.erg = v.w;
		}		
	}
	
	for(const auto& q : queries) cout << q.erg << "\n";
	
  return 0;
}
