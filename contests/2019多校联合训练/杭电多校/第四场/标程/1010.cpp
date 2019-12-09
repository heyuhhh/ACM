#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=4000;
int T,i,j,tot,v[N],p[N];ll n;
inline ll po(ll a,int b){
  ll ret=1;
  while(b--)ret*=a;
  return ret;
}
inline bool check(ll n,int k){
  ll t=pow(n,1.0/k);
  t-=5;
  if(t<1)t=1;
  while(po(t+1,k)<=n)t++;
  return po(t,k)==n;
}
inline void up(int&a,int b){if(a>b)a=b;}
inline int solve(ll n){
  int ret=100,i;
  for(i=0;i<tot&&p[i]<=n;i++)if(n%p[i]==0){
    int t=0;
    while(n%p[i]==0)t++,n/=p[i];
    up(ret,t);
  }
  if(n==1)return ret;
  for(i=4;i>=2;i--)if(check(n,i)){
    up(ret,i);
    return ret;
  }
  return 1;
}
int main(){
  for(i=2;i<N;i++)if(!v[i]){
    p[tot++]=i;
    for(j=i;j<N;j+=i)v[j]=1;
  }
  scanf("%d",&T);
  while(T--){
    scanf("%lld",&n);
    printf("%d\n",solve(n));
  }
}
