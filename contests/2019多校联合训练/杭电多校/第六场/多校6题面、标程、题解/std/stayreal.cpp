#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100010;
int Case,n,i,j,a[N];ll A,B;
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    A=B=0;
    for(i=n,j=1;i;i--,j^=1)if(j)A+=a[i];else B+=a[i];
    printf("%lld %lld\n",A,B);
  }
}