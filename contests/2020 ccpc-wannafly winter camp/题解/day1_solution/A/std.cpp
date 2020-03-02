#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct atom{
	int l,r;
	void scan(){
		scanf("%d%d",&l,&r);
	}
};
const int N=5100;
const int mo=998244353;
int operator < (atom k1,atom k2){
	return k1.l+k1.r<k2.l+k2.r;
}
int n,inv[N];
atom A[N];
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo;
		k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int calc(atom k1,atom k2){
	int l=max(k1.l,k2.l);
	if (l>k1.r) return 0;
	int r=min(k1.r,k2.r);
	int ans=1ll*(l-k2.l+r-k2.l)*(r-l+1)/2%mo;
	ans=(ans+1ll*(k1.r-r)*(k2.r-k2.l+1))%mo;
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) A[i].scan();
	sort(A+1,A+n+1);
	int ans=0;
	for (int i=1;i<=n;i++) inv[i]=quick(A[i].r-A[i].l+1,mo-2);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			ans=(ans+1ll*inv[i]*inv[j]%mo*calc(A[i],A[j]))%mo;
	cout<<ans<<endl;
	return 0;
}