#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

const int N = 105 ;
int f[N],sum[N];
int t,n,m;

void init(){
	memset(sum,0,sizeof(sum));
	for(int i=0;i<=n+1;i++) f[i]=i;
}

int find(int x){
	if(f[x]==x) return x;
	int tmp = f[x];
	f[x]=find(f[x]);
	sum[x]+=sum[tmp];
	return f[x];
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		init();
		bool flag =true ;
		for(int i=1,x,y,w;i<=m;i++){
			scanf("%d%d%d",&x,&y,&w);y++;
			int fx = find(x),fy=find(y);
			if(fx==fy){
				if(sum[y]-sum[x]!=w)
					flag = false ;
			}else{
				f[fy]=fx;
				sum[fy]=sum[x]-sum[y]+w;
			}
		}
		if(flag) puts("true");
		else puts("false");
	}
	return 0;
}
