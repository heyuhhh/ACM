#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define INF 1e9+7
#define mem(x) memset(x,0,sizeof(x))
using namespace std;

const int N = 415 , M = 30005 ;
int t,n,m,ans;
int match[N],w[N][N],l[N],r[N],slack[N],visx[N],visy[N];

void init(){
	mem(match);mem(r);ans=0;
	for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) w[i][j]=INF;
	for(int i=1;i<=N;i++) l[i]=-INF;
}

int dfs(int x){
	visx[x]=1;
	for(int i=n+1;i<=2*n;i++){
		if(w[x][i]==INF || visy[i]) continue ;
		int tmp = l[x]+r[i]-w[x][i];
		if(!tmp){
			visy[i]=1;
			if(!match[i] || dfs(match[i])){
				match[i]=x;
				return 1;
			}
		}else{
			slack[i]=min(slack[i],tmp);
		}
	}
	return 0;
} 

void update(){
	int d=INF;
	for(int i=n+1;i<=2*n;i++) if(!visy[i]) d=min(d,slack[i]);
	for(int i=1;i<=n;i++) if(visx[i]) l[i]-=d;
	for(int i=n+1;i<=2*n;i++) if(visy[i]) r[i]+=d;else slack[i]-=d; 
}

int KM(){
	for(int i=1;i<=n;i++){
		fill(slack,slack+N,INF);
		while(1){
			mem(visx);mem(visy);
			if(dfs(i)) break;
			update();
		}
	}
	for(int i=n+1;i<=n*2;i++) ans+=w[match[i]][i];
	return ans;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1,x,y,c;i<=m;i++){
			scanf("%d%d%d",&x,&y,&c);
			w[x][y+n]=min(w[x][y+n],c);
		}
		for(int i=1;i<=n;i++)
			for(int j=n+1;j<=2*n;j++)
				if(w[i][j]!=INF) w[i][j]=-w[i][j],l[i]=max(l[i],w[i][j]);
		printf("%d\n",-KM());
	}
	return 0;
} 
