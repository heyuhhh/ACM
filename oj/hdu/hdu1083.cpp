#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 305;
int n,m,t,ans;
int check[N],match[N],link[N][N];

inline int dfs(int x){
	for(int i=1;i<=m;i++){
		if(!check[i] && link[x][i]){
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
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		ans =0 ;
		memset(link,0,sizeof(link));memset(match,-1,sizeof(match));
		for(int i=1,x;i<=n;i++){
			scanf("%d",&x);
			for(int j=1,k;j<=x;j++){
				scanf("%d",&k);
				link[i][k]=1;
			}
		}
		for(int i=1;i<=n;i++){
			memset(check,0,sizeof(check));
			if(dfs(i)) ans++;
		}
		if(ans==n) puts("YES");
		else puts("NO");
	}
	return 0;
}
