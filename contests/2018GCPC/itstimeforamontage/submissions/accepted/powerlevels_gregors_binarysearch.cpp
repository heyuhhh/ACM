#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> h(n), v(n);
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int low = 0; 
	int high = 1e6+1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		vector<int> z(h.begin(), h.end());
		for (int i = 0; i < n; ++i) 
			z[i] += mid;
		if (z < v)
			low = mid+1;
		else
			high = mid-1;
	}
	cout << low << endl;
}
