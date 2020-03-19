#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;

const int N = 1505 ;
int check[N],match[N];
int n,ans,dfn;
vector<int> link[N];

inline int dfs(int x){
	for(int i=0;i<link[x].size();i++){
		int now = link[x][i];
		if(check[now]!=dfn){
			check[now]=dfn;
			if(match[now]==-1 || dfs(match[now])){
				match[now]=x;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++) link[i].clear();
		mem(link,0);mem(match,-1);ans=dfn=0;
		for(int i=0,u,k;i<n;i++){
			scanf("%d:(%d)",&u,&k);
			for(int j=1,v;j<=k;j++){
				scanf("%d",&v);
				link[u].push_back(v);
				link[v].push_back(u); 
			}
		}
		for(int i=0;i<n;i++){
			dfn++;
			if(dfs(i)) ans++;
		}
		printf("%d\n",ans/2);
	}
	return 0;
}
