#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int n; cin >> n;
	map<int, vector<int>> monsters;
	for (int i = 0; i < n; ++i)
	{
		int m; cin >> m;
		monsters[m].push_back(i);
	}
	if (monsters[1].size() >= 2)
	{
		cout << monsters[1][0]+1 << " " << monsters[1][1]+1 << endl;
		return 0;
	}
	int a = 1; int b = 1;
	do
	{
		a += b;
		swap(a,b);
		if (monsters.count(a) && monsters.count(b))
		{
			cout << monsters[a][0]+1 << " " << monsters[b][0]+1 << endl;
			return 0;
		}

	} while (a < monsters.rbegin()->first);
	cout << "impossible" << endl;
}
