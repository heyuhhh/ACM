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

int N,M;
int G[1024][1024];


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
	cin>>N>>M;
	for(int i=0;i<1024;i++) for(int j=0;j<1024;j++) G[i][j] = -1;
	for(int i=0;i<M;i++)
	{
		int s,t,c;
		cin>>s>>t>>c;
		G[s-1][t-1] = max(G[s-1][t-1], c);
	}
	for(int k=0;k<N;k++) for(int i=0;i<N;i++) for(int j=0;j<N;j++)
	{
		if(G[i][k] >= 0 && G[k][j] >= 0 && G[i][j] < G[i][k] + G[k][j]) G[i][j] = G[i][k] + G[k][j];
	}
	int bestv = 0;
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(G[i][j] > bestv) bestv = G[i][j];	
	cout << bestv << "\n";
	
  return 0;
}
