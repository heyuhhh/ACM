#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
double a[11000],s,f;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%d", &n);
        for (int i=1;i<=n;i++)scanf("%lf", &a[i]);
        sort(a+1, a+n+1);
        s = 0; f = 1;
        for (int i=n;i;i--)
            if (s*(1-a[i])+f*a[i]>s)
            {
                s=s*(1-a[i])+f*a[i];
                f=f*(1-a[i]);
            }
        printf("%.12f\n", s);
    }
    return 0;
}
