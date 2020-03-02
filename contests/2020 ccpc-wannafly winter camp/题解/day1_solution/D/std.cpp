#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
const int mo=998244353;
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo;
		k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
const int N=410;
int x[N][N<<1],y[N][N];
int n;
char A[N][N],B[N][N];
int solve(int n,int m){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) x[i][j]=(x[i][j]+mo)%mo;
	int pd=1;
	for (int i=1;i<=n;i++){
		int r=i;
		for (int j=i;j<=n;j++) if (x[j][i]){
			r=j; break;
		}
		if (r!=i){
			for (int j=1;j<=m;j++) swap(x[i][j],x[r][j]);
			pd=(mo-pd)%mo;
		}
		pd=1ll*pd*x[i][i]%mo;
		int rev=quick(x[i][i],mo-2);
		for (int j=1;j<=m;j++) x[i][j]=1ll*x[i][j]*rev%mo;
		for (int j=1;j<=n;j++)
			if (j!=i){
				int now=x[j][i];
				for (int k=1;k<=m;k++)
					x[j][k]=(x[j][k]-1ll*x[i][k]*now%mo+mo)%mo;
			}
	}
	return pd;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%s",A[i]+1);
	for (int i=1;i<=n;i++) scanf("%s",B[i]+1);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (A[i][j]=='1'){
				x[i][j]-=1; x[i][i]+=1;
			}
			if (A[i][j]=='1'&&B[i][j]=='1'){
				y[i][j]=mo-1; y[i][i]+=1;
			}
		}
	}
	n--;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) x[i][j+n]=0;
	for (int i=1;i<=n;i++) x[i][i+n]=1;
	int r=solve(n,n<<1);
	assert(r);
	int ans=0;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;j++)
			ans=(ans+1ll*x[i][j+n]*y[i][j])%mo;
	ans=1ll*ans*r%mo;
	cout<<ans<<endl;
}