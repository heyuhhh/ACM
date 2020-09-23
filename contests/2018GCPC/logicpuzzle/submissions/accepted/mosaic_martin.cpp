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
using namespace std;
#ifdef DEBUG
#define db(a) (cout << (#a) << " = " << (a) << endl)
#else
#define db(a)
#endif
using ll = long long;

int H,W;

char M[128][128];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  for(int h=0;h<H+2;h++)	for(int w=0;w<W+2;w++) M[h][w] = '.';
  
  cin>>H>>W;
  bool fail = false;
	for(int h=0;h<H+2 && !fail;h++)
	{
		int current = 0;
		if(h>0 && M[h-1][1] == 'X') ++current;
		if(M[h][1] == 'X') ++current;
		for(int w=0;w<W+2;w++)
		{
			int c;
			cin>>c;
			if(current+1 == c && w+1 < W+2 && h+1 < H+2)
			{
				++current;
				if(w > 0 && h+1 < H+2 && M[h+1][w-1] == 'X') --current;
				if(w > 0 && M[h][w-1] == 'X') --current;
				if(w > 0 && h > 0 && M[h-1][w-1] == 'X') --current;
				if(w+2 < W+2 && M[h][w+2] == 'X') ++current;
				if(w+2 < W+2 && h > 0 && M[h-1][w+2] == 'X') ++current;
				if(w+1 < W+2 && h+1 < H+2) M[h+1][w+1] = 'X';
			}
			else if(current == c)
			{
				if(w > 0 && h+1 < H+2 && M[h+1][w-1] == 'X') --current;
				if(w > 0 && M[h][w-1] == 'X') --current;
				if(w > 0 && h > 0 && M[h-1][w-1] == 'X') --current;
				if(w+2 < W+2 && M[h][w+2] == 'X') ++current;
				if(w+2 < W+2 && h > 0 && M[h-1][w+2] == 'X') ++current;
				if(w+1 < W+2 && h+1 < H+2) M[h+1][w+1] = '.';
			}
			else
			{
				db(h);
				db(w);
				db(c);
				db(current);
				fail = true;
				break;
			}
		}
	}
	
	if(fail) cout << "impossible\n";
	else
	{
		for(int h=1;h<H+1;h++)
		{
			for(int w=1;w<W+1;w++) cout << M[h][w];
			cout << "\n";
		}
	}
	
  return 0;
}
