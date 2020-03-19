#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define mem(x) memset(x,0,sizeof(x))
using namespace std;

const int N = 510 ;
int n,t,m,ans;
int check[N],match[N],map[N][N];

inline int dfs(int x){
	for(int i=n+1;i<=2*n;i++){
		if(map[x][i] && !check[i]){
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
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		mem(map);mem(match);ans=0;
		for(int i=1,x,y;i<=m;i++){
			scanf("%d%d",&x,&y);
			map[x][y+n]=1;
		}
		for(int i=1;i<=n;i++){
			mem(check);
			if(dfs(i)) ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
