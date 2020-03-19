#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue> 
using namespace std;
const int N = 3005 ;
int T,t,n,m,ans,lim,cnt=0;
int d[N][N],link[N][N],match[N],match2[N],check[N],disx[N],disy[N];
struct guests{
	int x,y,v;
}g[N];
inline void init(){
	memset(link,0,sizeof(link));memset(match,-1,sizeof(match));
	ans=0;cnt++;memset(check,0,sizeof(check));memset(match2,-1,sizeof(match2));
}
inline int dfs(int x){
	for(int i=1;i<=n;i++){
		if(disy[i]==disx[x]+1 && !check[i] &&link[x][i]){
			check[i]=1;
			if(match[i]!=-1 && disy[i]==lim) continue ;//此时增广路会大于lim 
			if(match[i]==-1 || dfs(match[i])){
				match[i]=x;
				match2[x]=i;
				return 1;
			}
		}
	}
	return 0;
}
inline bool bfs(){
	queue<int> q;
	memset(disx,-1,sizeof(disx));
	memset(disy,-1,sizeof(disy));lim = (1<<30);
	for(int i=1;i<=m;i++) if(match2[i]==-1){
		q.push(i);disx[i]=0;
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		if(disx[u]>lim) break ; //条件成立，所求增广路必然比当前的增广路长度长 
		for(int i=1;i<=n;i++){
			if(link[u][i] && disy[i]==-1){
				disy[i]=disx[u]+1;
				if(match[i]==-1) lim=disy[i];//找到增广路，记录长度 
				else{
					disx[match[i]]=disy[i]+1;
					q.push(match[i]);//入队，寻找更长的增广路 
				}
			}
		}
	}
	return lim!=(1<<30) ;
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&t,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&g[i].x,&g[i].y,&g[i].v);
		}
		scanf("%d",&n);
		for(int i=1,x,y;i<=n;i++){
			scanf("%d%d",&x,&y);
			for(int j=1;j<=m;j++){
				d[j][i]=abs(g[j].x-x)+abs(g[j].y-y);
				if(d[j][i]<=t*g[j].v) link[j][i]=1;
			}
		}
		while(bfs()){
			memset(check,0,sizeof(check));
			for(int i=1;i<=m;i++){
				if(dfs(i)) ans++;
			}
		}
		printf("Scenario #%d:\n%d\n\n",cnt,ans);
	}
	
	return 0;
}
