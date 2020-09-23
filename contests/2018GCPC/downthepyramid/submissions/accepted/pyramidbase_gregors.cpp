#include <iostream>
using namespace std;
typedef long long LL;
int main()
{
	int n; cin >> n;
	LL sum = 0, x = 0, y = 1e9;
	for (int i = 0; i < n; ++i)
	{
		LL k; cin >> k;
		sum = -sum + k;
		if (i % 2)
			x = max(x, -sum);
		else
			y = min(y, sum);
	}
	LL res = y-x+1;
	if (res > 0)
		cout << res << endl;
	else
		cout << "0" << endl;
}
