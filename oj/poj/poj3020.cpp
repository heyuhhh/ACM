#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mem(x) memset(x,0,sizeof(x))
using namespace std;

const int N = 45 ;
int map[N][N],check[N*10],match[N*10],vis[N*10],link[N*10][N*10];
int n,m,t,tot,ans,dfn;
char s[N]; 
inline void init(){
	mem(map);mem(match);mem(link);mem(check);
	mem(vis);tot=0;ans=0;dfn=0;
}
inline void update(int x,int y){
	if(map[x+1][y]) link[map[x][y]][map[x+1][y]]=1;
	if(map[x-1][y]) link[map[x][y]][map[x-1][y]]=1;
	if(map[x][y+1]) link[map[x][y]][map[x][y+1]]=1;
	if(map[x][y-1]) link[map[x][y]][map[x][y-1]]=1;
}
inline int dfs(int x){
	for(int i=1;i<=tot;i++){
		if(link[x][i] && check[i]!=dfn){
			check[i]=dfn;
			if(!match[i] || dfs(match[i])){
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=m;j++) if(s[j]=='*') map[i][j]=++tot;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(map[i][j]) update(i,j);
		for(int i=1;i<=tot;i++){
			dfn++;
			if(dfs(i)) ans++;
		}
		for(int i=1;i<=tot;i++) if(match[i]) vis[match[i]]=vis[i]=1;
		for(int i=1;i<=tot;i++) if(!vis[i]) ans+=2;
		printf("%d\n",ans/2);
	}
	return 0;
}
