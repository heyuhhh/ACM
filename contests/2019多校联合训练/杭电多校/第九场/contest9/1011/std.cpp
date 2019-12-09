#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
using namespace std;
int ans,prec[70];
long long L,R;
const int mo=998244353,inv2=(mo+1)/2;
map<long long,int> M;
int get1(long long n){
	n%=mo; return n*(n+1)/2%mo;
}
int get2(long long n){
	n%=mo; long long ans=n*(n+1)/2;
	if (ans%3==0) return ans/3%mo*(2*n+1)%mo;
	else return (2*n+1)/3*(ans%mo)%mo;
}
int getdepth(long long n){
	int D=63-__builtin_clzll(n);
	return (n%mo*(D+1)+2*(n-(1ll<<D)))%mo;
}
int getsumK(int k,long long L,long long R){
	assert(L>=(1ll<<k)&&R<(1ll<<k+1));
	int sum2=(get2(R)-get2(L-1)+mo)%mo;
	int sum1=(get1(R)-get1(L-1)+mo)%mo;
	int sum0=(R-L+1)%mo;
	int ans=(2ll*(k+3)*sum2+(k+3-(1ll<<k+2))%mo*sum1%mo-(1ll<<k+1)%mo*sum0)%mo;
	return ans;
}
int getsum(long long n){
	if (n==0) return 0;
	int D=63-__builtin_clzll(n);
	int ans=0; if (D) ans=prec[D-1];
	ans=(ans+getsumK(D,(1ll<<D),n))%mo;
	return ans;
}
int getans(long long n){
	if (n<=1) return n==1;
	if (M[n]) return M[n]-1;
	int m=n%mo; int ans=0;
	if (n&1){
		ans=(ans+3ll*getans(n/2)+getans(n/2+1))%mo;
	} else {
		ans=(ans+getans(n/2-1)+3ll*getans(n/2))%mo;
	}
	//cout<<n<<" "<<ans<<endl;
	int w1=(get1(n)+mo-1)%mo,w2=(get2(n)+mo-1)%mo;
	ans=(ans+getsum((n-1)/2))%mo;
	if (n%2==0){
		ans=(ans+n/2%mo*(getdepth(n/2)))%mo;
	}
	//cout<<n<<" "<<ans<<endl;
	ans=(ans+1ll*(w1+w2)*inv2)%mo;
	//cout<<"ans "<<n<<" "<<ans<<endl;
	M[n]=ans+1; return ans;
}
void solve(){
	scanf("%lld%lld",&L,&R);
	//cout<<getans(R)<<" "<<getans(L-1)<<endl;
	int ans=(getans(R)-getans(L-1)+mo)%mo;
	printf("%d\n",ans);
}
int main(){
	for (int i=0;i<60;i++) prec[i]=getsumK(i,1ll<<i,(1ll<<i+1)-1);
	for (int i=1;i<60;i++) prec[i]=(prec[i-1]+prec[i])%mo;
	//for (int i=0;i<=3;i++) cout<<prec[i]<<" "; cout<<endl;
	int t; scanf("%d",&t);
	for (;t;t--) solve();
}