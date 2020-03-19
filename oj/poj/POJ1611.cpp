#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 30005 ,M = 505;
int n,m;
vector <int > vec[N];
vector <int > g[M];
int vis[N],check[M];

int main(){
	while(scanf("%d%d",&n,&m)){
		if(n==0 && m==0) break;
		queue <int > q;memset(vis,0,sizeof(vis));memset(check,0,sizeof(check));
		for(int i=0;i<=n;i++) vec[i].clear();
		for(int i=0;i<=m;i++) g[i].clear();
		for(int i=1,k;i<=m;i++){
			scanf("%d",&k);
			for(int j=1,num;j<=k;j++){
				scanf("%d",&num);
				vec[num].push_back(i);
				if(!num){
					if(!check[i]) q.push(i);
					check[i]=1;
				}
				g[i].push_back(num);
			}
		}
		vis[0]=1;
		while(!q.empty()){
			int now = q.front();q.pop();
			for(int i=0;i<g[now].size();i++){
				int t = g[now][i];
				if(!vis[t]){
					vis[t]=1;
					for(int j=0;j<vec[t].size();j++){
						if(!check[vec[t][j]]){
							check[vec[t][j]]=1;
							q.push(vec[t][j]);
						}
					}
				}
			}
		}
		int ans = 0;
		for(int i=0;i<=n;i++) if(vis[i]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
/*
1 0 
345678 0
*/
