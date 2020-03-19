#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 4005;
int t,n,m;
int f[N];

int find(int x){
	return f[x]==x ? f[x] :f[x]=find(f[x]); 
}
bool same(int x,int y){
	return find(x)==find(y);
}
void Union(int x,int y){
	int fx=find(x),fy=find(y);
	f[fx]=fy;
}
int main(){
	scanf("%d",&t);int tot=0;
	while(t--){
		tot++;
		bool flag=true;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=N-5;i++) f[i]=i;
		for(int i=1,x,y;i<=m;i++){
			scanf("%d%d",&x,&y);
			if(!flag) continue ;
			int fx=find(x),fy=find(y);
			if(!same(x,y) && !same(x+n,y+n)){
				Union(x,y+n);Union(x+n,y);
			}else flag=false;
		}
		printf("Scenario #%d:\n",tot);
		if(flag) puts("No suspicious bugs found!");
		else puts("Suspicious bugs found!");
		printf("\n");
	}
	return 0;
}
