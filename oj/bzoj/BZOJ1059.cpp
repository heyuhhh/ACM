#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 205 ;
int n,t;
int Link[N][N],match[N],check[N];

int dfs(int x){
	for(int i=1;i<=n;i++){
		if(!check[i] && Link[x][i]){
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
		scanf("%d",&n);
		memset(Link,0,sizeof(Link));memset(match,0,sizeof(match));
		for(int i=1;i<=n;i++){
			for(int j=1,x;j<=n;j++){
				scanf("%d",&x);
				if(x) Link[i][j]=1;
			}
		}
		int ans = 0;
		for(int i=1;i<=n;i++){
			memset(check,0,sizeof(check));
			ans+=dfs(i);
		}
		if(ans==n) puts("Yes");
		else puts("No");
	}
	return 0;
}
