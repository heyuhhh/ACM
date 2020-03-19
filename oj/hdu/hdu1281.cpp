#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 105;
int map[N][N],check[N],match[N];
int n,m,k,ans,l,t=0;

inline void init(){
	memset(match,-1,sizeof(match));
	memset(check,0,sizeof(check));
	ans=0;l=0;memset(map,0,sizeof(map));
}

inline int dfs(int x){
	for(int i=1;i<=m;i++){
		if(map[x][i] && !check[i]){
			check[i]=1;
			if(match[i]==-1 || dfs(match[i])){
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		init();
		++t;
		for(int i=1,x,y;i<=k;i++){
			scanf("%d%d",&x,&y);
			map[x][y]=1;
		}
		for(int i=1;i<=n;i++){
			memset(check,0,sizeof(check));
			if(dfs(i)) ans++;
		}
		int cnt;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(map[i][j]){
					map[i][j]=0;cnt=0;memset(match,-1,sizeof(match));
					for(int k=1;k<=n;k++){
						memset(check,0,sizeof(check));
						if(dfs(k)) cnt++;
					}
					map[i][j]=1;
					if(cnt!=ans) l++;
				}
			}
		}
		printf("Board %d have %d important blanks for %d chessmen.\n",t,l,ans);
	}
	return 0;
}
