#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 30005 ,M = 505;
int n,m;
int f[N+M];

int find(int x){
	return f[x]==x ? x : f[x]=find(f[x]);
}

void Union(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	f[fx]=fy;
}

int main(){
	while(scanf("%d%d",&n,&m)){
		if(!n && !m) break;
		for(int i=0;i<=n+m+1;i++) f[i]=i;
		for(int i=1,k;i<=m;i++){
			scanf("%d",&k);
			for(int j=1,num;j<=k;j++){
				scanf("%d",&num);
				Union(num,n+i);
			}
		}
		int ans = 0,std=find(0);
		for(int i=0;i<=n;i++){
			if(std==find(i)) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
