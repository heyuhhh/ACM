//带权并查集 
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 5e4+5;
int f[N],r[N]={0};
int n,k,ans=0;

int find(int x){
	if(f[x]==x) return x;
	int tmp = f[x];
	f[x]=find(f[x]);
	r[x]=(r[x]+r[tmp])%3;
	return f[x];
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n+1;i++) f[i]=i;
	while(k--){
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(x<1 || y>n ||x>n ||y<1){ans++;continue ;}
		int fx=find(x),fy=find(y);
		if(fx==fy){
			if((r[x]-r[y]+3)%3!=op-1) ans++;
		}else{
			f[fy]=fx;
			if(op==1) r[fy]=(r[x]+(3-r[y]))%3;
			else r[fy]=(r[x]+(3-r[y])+op);
		}
	}
	printf("%d",ans);
	return 0;
}
