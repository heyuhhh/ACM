#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define mem(x) memset(x,0,sizeof(x))
using namespace std;

const int N = 605 ;
int check[N],match[N],map[N][N],link[N][N];
int Case,n,tot,ans,dfn,t=0;

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
			if(match[i]==0 || dfs(match[i])){
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d",&Case);
	while(Case--){
		t++;
		scanf("%d",&n);
		mem(map);mem(match);mem(link);tot=0;ans=0;dfn=0;mem(check);
		for(int i=1;i<=n;i++){
			char s[N];
			scanf("%s",s+1);
			for(int j=1;j<=n;j++){
				if(s[j]=='#') map[i][j]=++tot;
			}
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(map[i][j]) update(i,j);
		for(int i=1;i<=tot;i++){
			dfn++;
			if(dfs(i)) ans++;
		}
		printf("Case %d: %d\n",t,ans/2);
	}
	return 0;
}
