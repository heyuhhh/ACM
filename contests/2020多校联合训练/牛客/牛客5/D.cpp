#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define LC k<<1
#define RC k<<1|1
 
typedef long long LL;
const int N=510;
const int M=1100000;
const LL mod=1e9+7;
 
int n;
int a[N],b[N], f[N];
int ans;
int main()
{
    freopen("input.in", "r", stdin);
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]),a[i]--;
    ans=n;
    for (int i=0;i<n;i++)
    {
        int tmp=0;
        for (int j=0;j<n;j++)
            b[(i+j)%n]=a[j];
        for (int j = 0; j < n; j++) {
            f[j] = 1;
        }
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < j; k++) {
                if (b[j] > b[k])
                f[j] = max(f[j], f[k] + 1);
            }
        }
        for (int j = 0; j < n; j++) {
            tmp = max(tmp, f[j]);
        }
        ans=min(ans,n - tmp);
    }
    printf("%d\n",ans);
    return 0;
}