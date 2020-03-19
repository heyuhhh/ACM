#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int  N = 205;
int link[N][N],match[N],check[N],color[N];
int n,m,ans=0;

inline void init(){
	ans=0;memset(color,-1,sizeof(color));
	memset(link,0,sizeof(link));memset(match,-1,sizeof(match));
}

inline int dfs(int x){
	for(int i=1;i<=n;i++){
		if(link[x][i] && !check[i]){
			check[i]=1;
			if(match[i]==-1 || dfs(match[i])){
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
inline bool ok(int x){ //二分图染色 
	for(int i=1;i<=n;i++){
		if(link[x][i]){
			if(color[i]==-1){
				color[i]=1-color[x];
				if(!ok(i)) return false;
			}else if(color[i]==color[x]) return false ;
		}
	}
	return true;
}
/*dfs实现 ，连通图直接调用ok(1,0) 
inline bool ok(int x,int c){ 
	color[x]=c;
	for(int i=1;i<=n;i++){
		if(link[x][i]){
			if(color[i]==-1){
				if(!ok(i,1-color[x])) return false;
			}else if(color[i]==color[x]) return false ;
		}
	}
	return true;
}
*/ 
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		for(int i=1,a,b;i<=m;i++){
			scanf("%d%d",&a,&b);
			link[a][b]=1;
			link[b][a]=1;
		}
		bool flag=false ;
		for(int i=1;i<=n;i++){
			if(color[i]==-1){
				color[i]=0;
				if(!ok(i)){
					flag=true;break;
				}
			}
		}
		if(flag){
			puts("No");continue;
		}
		for(int i=1;i<=n;i++){
			memset(check,0,sizeof(check));
			if(dfs(i)) ans++;
		}
		printf("%d\n",ans/2);
	}
	return 0;
}
