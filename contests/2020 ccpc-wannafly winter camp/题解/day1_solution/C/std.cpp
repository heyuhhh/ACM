#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int L,R,n;
const int mo=998244353;
int get(int l,int r){
	return 1ll*(l+r)*(r-l+1)/2%mo;
}
int get(int n,int l,int r){
	int k1=(n-1)/l+1,k2=n/l;
	int w1=1ll*k1*(k1-1)/2%mo;
	int ans=1ll*n*(r-l+1)%mo*w1%mo;
	w1=1ll*w1*(n/l)%mo;
	ans=(ans-1ll*get(l,r)*w1%mo+mo)%mo;
	int w2=1ll*k2*(k2-1)/2%mo;
	ans=(ans+1ll*get(l,r)*(n/l+1)%mo*w2)%mo;
	ans=(ans-1ll*n*w2%mo*(r-l+1))%mo;
	return ans;
}
int f(int n,int K){
	int size1=n/K,num1=K-n%K;
	int size2=size1+1,num2=n%K;
	return (1ll*size1*(size1-1)/2%mo*num1+1ll*size2*(size2-1)/2%mo*num2)%mo;
}
void solve(){
	scanf("%d%d%d",&n,&L,&R);
	int ans=0;
	for (int i=L,ne;i<=R&&i<=n-1;i=ne+1){
		ne=min(n/(n/i),(n-1)/((n-1)/i));
		ne=min(ne,R);
		ans=(ans+get(n,i,ne))%mo;
	}
	ans=(1ll*n*(n-1)/2%mo*(R-L+1)-ans+mo)%mo;
	printf("%d\n",ans);
}
int main(){
	int t; scanf("%d",&t);
	for (;t;t--) solve();
}