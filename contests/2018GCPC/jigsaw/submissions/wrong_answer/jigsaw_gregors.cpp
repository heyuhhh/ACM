#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<vector<int>> parts;
vector<vector<int>> connectors(1e6);

bool rotateFit(int p, int leftCon, int upCon)
{
	int j = -1;
	while (++j < 4 && (parts[p][j] != leftCon || parts[p][(j+3)%4] != upCon));
	if (j == 4) return false;
	rotate(parts[p].begin(), parts[p].begin()+j, parts[p].end());
	return true;
}

int findPart(int leftCon, int upCon, int leftNeigh, int upNeigh)
{
	int p = -1;
	if (leftCon != 0)
		p = connectors[leftCon][0] + connectors[leftCon][1] - leftNeigh;
	else if (upCon != 0)
		p = connectors[upCon][0] + connectors[upCon][1] - upNeigh;
	if (p == -1 || p == leftNeigh || p == upNeigh || !rotateFit(p, leftCon, upCon))
		return -1;
	return p;
}

void impossible()
{
	printf("impossible\n");
	exit(0);
}

int main()
{
	int n; scanf("%d", &n);
	int maxZeros = 0;
	int cur = -1;
	parts.resize(n, vector<int>(4,0));
	for (int i = 0; i < n; ++i)
	{
		int numZeros = 0;
		for (int j = 0; j < 4; ++j)
		{
			int k; scanf("%d", &k);
			parts[i][j] = k;
			if (k != 0)
				connectors[k].push_back(i);
			numZeros += k==0;
		}
		if (numZeros > maxZeros)
			maxZeros = numZeros, cur = i;
	}
	if (maxZeros <= 1)
		impossible();
	else if (maxZeros == 2 && !rotateFit(cur,0,0))
		impossible();
	else if (maxZeros == 3)
	{
		int j = -1;
		while (parts[cur][++j] == 0);
		rotate(parts[cur].begin(), parts[cur].begin()+((j+2)%4), parts[cur].end());
	}	
	else if (maxZeros == 4 && n == 1)
		printf("1 1\n1\n"), exit(0);
	vector<vector<int>> puzzle(1);
	puzzle.back().push_back(cur);
	int row = 0, col = 1;
	int leftNeigh = cur, leftCon = parts[cur][2];
	int upNeigh = -1, upCon = 0;
	while(true) 
	{
		cur = findPart(leftCon, upCon, leftNeigh, upNeigh);
		if (cur == -1)
			impossible();
		puzzle.back().push_back(cur);
		col++;
		leftNeigh = cur, leftCon = parts[leftNeigh][2];
		if (leftCon == 0)
		{
			leftNeigh = -1, leftCon = 0;
			upNeigh = puzzle.back()[0], upCon = parts[upNeigh][1];
			if (leftCon == 0 && upCon == 0)
				break;
			puzzle.push_back(vector<int>());
			row++;
			col = 0;
		}
		else if (row == 0 || col >= puzzle[row-1].size())
			upNeigh = -1, upCon = 0;
		else
			upNeigh = puzzle[row-1][col], upCon = parts[upNeigh][1];
	}
	int x = puzzle.size();
	int y = puzzle.back().size();
	if (x * y != n) impossible();
	for (int bottom : puzzle.back())
		if (parts[bottom][1] != 0)
			impossible();
	printf("%d %d\n", (int) puzzle.size(), (int) puzzle.back().size());
	for (vector<int> &vec : puzzle)
	{
		for (int k : vec)
			printf("%d ", k+1);
		printf("\n");
	}
}

