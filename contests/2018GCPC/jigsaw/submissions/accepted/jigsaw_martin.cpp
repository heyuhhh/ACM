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
#include <array>
using namespace std;
#ifdef DEBUG
#define db(a) (cout << (#a) << " = " << (a) << endl)
#else
#define db(a)
#endif
using ll = int64_t;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
 
	int N;
	cin>>N;
	vector<array<int, 4>> V(N);
	vector<bool> used(N, false);
	vector<pair<int, int>> M(4*N, {-1, -1});
	int topleft = -1;
	for(int n=0;n<N;n++) 
	{
		for(int i=3;i>=0;i--)
		{
			cin >> V[n][i];
			if(V[n][i] != 0)
			{
				if(M[V[n][i]].first < 0) M[V[n][i]].first = n;
				else M[V[n][i]].second = n;
			}
		}
		if(topleft < 0) for(int j=0;j<4;j++)
		{
			if(V[n][0] == 0 && V[n][1] == 0)
			{
				topleft = n;
				break;
			}
			rotate(V[n].begin(), V[n].begin() + 1, V[n].end());
		}
	}
	if(topleft < 0) { cout << "impossible\n"; return 0; }
	vector<vector<int>> erg(1, vector<int>(1));
	erg[0][0] = topleft;
	used[topleft] = true;
	size_t width = 1;
	for(;;width++)
	{
		int index = erg[0][width-1];
		int open = V[index][2];
		if(open == 0) break;
		int fit = M[open].first;
		if(fit == index) fit = M[open].second;
		while(V[fit][0] != open) rotate(V[fit].begin(), V[fit].begin() + 1, V[fit].end());
		if(V[fit][1] != 0 || used[fit]) { cout << "impossible\n"; return 0; }
		used[fit] = true;
		erg[0].push_back(fit);
	}
	size_t height = 1;
	for(;;height++)
	{
		erg.push_back(vector<int>(1));
		int index = erg[height-1][0];
		int open = V[index][3];
		if(open == 0) break;
		int fit = M[open].first;
		if(fit == index) fit = M[open].second;
		while(V[fit][1] != open) rotate(V[fit].begin(), V[fit].begin() + 1, V[fit].end());
		if(V[fit][0] != 0 || used[fit]) { cout << "impossible\n"; return 0; }
		used[fit] = true;
		erg[height][0] = fit;
		for(size_t w=1;w<width;w++)
		{
			int index = erg[height][w-1];
			int open = V[index][2];
			if(open == 0) { cout << "impossible\n"; return 0; }
			int fit = M[open].first;
			if(fit == index) fit = M[open].second;
			while(V[fit][0] != open) rotate(V[fit].begin(), V[fit].begin() + 1, V[fit].end());
			if(V[fit][1] == 0 || V[fit][1] != V[erg[height-1][w]][3] || used[fit]) { cout << "impossible\n"; return 0; }
			used[fit] = true;
			erg[height].push_back(fit);
		}
		if(V[erg[height][width-1]][2] != 0) { cout << "impossible\n"; return 0; }
	}
	for(size_t w=1;w<width;w++) if(V[erg[height-1][w]][3] != 0) { cout << "impossible\n"; return 0; }
	if(height * width != static_cast<size_t>(N)) { cout << "impossible\n"; return 0; }
	cout << height << " " << width << "\n";
	for(size_t h=0;h<height;h++)
	{
		cout << erg[h][0]+1;
		for(size_t w=1;w<width;w++) cout << " " << erg[h][w]+1;
		cout << "\n";
	}

  return 0;
}
