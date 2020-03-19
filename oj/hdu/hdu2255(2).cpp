#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define mem(x) memset(x,0,sizeof(x))
#define INF 0x3f3f3f
using namespace std;

const int N = 305 ;
int match[N],slack[N],w[N][N],l[N],r[N],visx[N],visy[N];
int n,ans;

int dfs(int x){
	visx[x]=1;
	for(int i=1;i<=n;i++){
		int tmp = l[x]+r[i]-w[x][i];
		if(visy[i]) continue ;
			if(!tmp){
				visy[i]=1;
				if(!match[i] || dfs(match[i])){
					match[i]=x;
					return 1;
				}
			}else slack[i]=min(slack[i],tmp);
	}
	return 0;
}

void KM(){
	for(int i=1;i<=n;i++){
		fill(slack,slack+n+1,INF);
		while(1){
			mem(visx);mem(visy);
			if(dfs(i)) break;
			int d=INF;
			for(int i=1;i<=n;i++) if(!visy[i]) d=min(d,slack[i]);
			for(int i=1;i<=n;i++){
				if(visx[i]) l[i]-=d;
				if(visy[i]) r[i]+=d;
				else slack[i]-=d;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans+=w[match[i]][i];
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		mem(match);mem(w);mem(l);mem(r);ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1,x;j<=n;j++){
				scanf("%d",&x);
				w[i][j]=x;
				l[i]=max(l[i],x);
			}
		}
		KM();
		printf("%d\n",ans);
	}
	return 0;
}
