#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 105 ;
int map[N][N],link[N][N],match[N],check[N],r[N],a[N],b[N];
int n,ans,tot;

inline void init(){
	memset(map,0,sizeof(map));memset(link,0,sizeof(link));
	memset(match,-1,sizeof(match));ans=0;tot=0;
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));
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

inline void Swap(){
	for(int i=1;i<=n;i++){
		if(match[i]!=i){
			a[++tot]=i;b[tot]=match[i];
			for(int j=1;j<=n;j++){
				if(match[j]==i){
					swap(match[i],match[j]);
					break ;
				}
			}
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		init();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&map[i][j]);
				if(map[i][j]) link[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++){
			memset(check,0,sizeof(check));
			if(dfs(i)) ans++;
		}
		if(ans!=n){
			puts("-1");continue ;
		}
		Swap();
		printf("%d\n",tot);
		for(int i=1;i<=tot;i++) printf("R %d %d\n",a[i],b[i]);
	}
	return 0;
}
