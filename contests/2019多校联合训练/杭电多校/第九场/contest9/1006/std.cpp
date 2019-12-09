#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N=1100,lim=40;
int A[N],n,ans=1e9,pd[lim+10];
const int w[4]={1,2,5,10};
const int num[4]={1,3,1,3};
void put(int k){
	for (int i=lim;i>=k;i--) pd[i]|=pd[i-k];
}
int calc(){
	int w=0;
	for (int i=1;i<=n;i++){
		int k=A[i]%10;
		int num=1e9;
		while (k<=lim&&k<=A[i]){
			if (pd[k]) num=min(num,(A[i]-k)/10);
			k+=10;
		}
		w=max(w,num);
	}
	return w;
}
void getans(int k,int tot){
	if (k==4){
		ans=min(ans,calc()+tot); return;
	}
	int back[lim+10]; memcpy(back,pd,sizeof pd);
	for (int i=0;i<=num[k];i++){
		getans(k+1,tot+i); put(w[k]);
	}
	memcpy(pd,back,sizeof back);
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&A[i]);
	}
	for (int i=1;i<=n;i++){
		if (A[i]%10){
			printf("-1\n"); return;
		}
		A[i]/=10;
	}
	ans=1e9; memset(pd,0x00,sizeof pd); pd[0]=1;
	getans(0,0);
	printf("%d\n",ans);
}
int main(){
	int t; scanf("%d",&t);
	for (;t;t--) solve();
	return 0;
}