#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;

int main()
{
	LL n; cin >> n;
	LL d = 3;
	do
	{
		LL x = n, s = 0;
		while (x > 0)
		{
			s++;
			LL p = 1;
			for (int i = 0; i < d-1; ++i)
				p *= s;
			x -= p;
		}
		if (x == 0)
			cout << d << " " << s << endl, exit(0);
	} while (1 + ((LL) 1 << (++d-1)) <= n);
	cout << "impossible" << endl;
}
