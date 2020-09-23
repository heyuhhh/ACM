#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> h(n), v(n);
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int k = max(v[0]-h[0], 0);
	int inc = 0;
	for (int i = 0; i < n; ++i)
	{
		if (h[i] + k != v[i])
		{
			inc = (h[i] + k) < v[i];
			break;
		}
	}
	cout << k + inc << endl;
}
