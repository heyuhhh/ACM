#include <iostream>
#include <cmath>
using namespace std;
const int MAX_P = 1e7+1;
const int FAC = 1e5;
const int MAX_N = 1e5;
bool s[MAX_P];
int a[MAX_N];
int b[MAX_N];

int gcd(int x, int y)
{
	while (y != 0)
	{
		x %= y;
		swap(x,y);
	}
	return x;
}

void eraSieve(int n)
{
	s[1] = true;
	for (int i = 2; i <= sqrt(n); ++i)
		if (!s[i])
			for (int j = i*i; j <= n; j += i)
				s[j] = true;
}

int main()
{
	int n;
	scanf("%d", &n);
	int maxAB = -1;
	for (int i = 0; i < n; ++i)
	{
		double x,y;
		scanf("%lf %lf", &x, &y);
		a[i] = x * FAC;
		b[i] = y * FAC;
		int g = gcd(a[i],b[i]);
		a[i] /= g;
		b[i] /= g;
		maxAB = max(maxAB, max(a[i],b[i]));
	}
	eraSieve(maxAB);
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 1 && b[i] == 1)
			printf("2 2\n");
		else if (!s[a[i]] && !s[b[i]])
			printf("%d %d\n", a[i], b[i]);
		else
			printf("impossible\n");
	}
}
