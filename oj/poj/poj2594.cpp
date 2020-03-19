#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define mem(x) memset(x,0,sizeof(x))
using namespace std;

const int N = 505 ;
int map[N][N],check[N<<1],match[N<<1],link[N][N<<1];
int n,m,ans;

inline int dfs(int x){
	for(int i=n+1;i<=2*n;i++){
		if(link[x][i] && !check[i]){
			check[i]=1;
			if(!match[i] || dfs(match[i])){
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	while(scanf("%d%d",&n,&m)){
		if(!n && !m) break ;
		mem(map);mem(match);mem(link);ans=0;
		for(int i=1,x,y;i<=m;i++){
			scanf("%d%d",&x,&y);
			map[x][y]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				if(map[i][k])
				for(int j=1;j<=n;j++){
					if(map[k][j]) map[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(map[i][j]) link[i][j+n]=1;
		for(int i=1;i<=n;i++){
			mem(check);
			if(dfs(i)) ans++;
		}
		printf("%d\n",n-ans);
	}	
	return 0;
} 
/*
7 6
2 3
1 3
3 7
3 4
4 5
4 6
*/
