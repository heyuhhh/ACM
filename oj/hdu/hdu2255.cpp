#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define INF 0x3f3f3f
using namespace std;

const int N = 305 ;
int w[N][N]={0},visx[N],visy[N],lx[N],ly[N]={0},matching[N],slack[N];
int n,d,ans=0;

inline int dfs(int x){
	visx[x]=1;//记录 
	for(int i=1;i<=n;i++){
		if(visy[i]) continue;
		int tmp = lx[x]+ly[i]-w[x][i];
		if(!tmp){ //可行边 
			visy[i]=1;
			if(matching[i]==-1 || dfs(matching[i])){
				matching[i]=x;
				return 1;
			}
		}else{
			if(slack[i]>tmp) slack[i]=tmp; //预处理 
		}
	}
	return 0;
}

inline int KM(){
	memset(matching,-1,sizeof(matching));
	ans=0;
	for(int i=1;i<=n;i++){
		memset(slack,INF,sizeof(slack)); //对于新的点，更新slack 
		while(1){
			memset(visx,0,sizeof(visx));memset(visy,0,sizeof(visy));
			if(dfs(i)) break;
			d=INF;
			for(int i=1;i<=n;i++) if(!visy[i]) if(d>slack[i]) d=slack[i];
			for(int i=1;i<=n;i++){
				if(visx[i]) lx[i]-=d;
				if(visy[i]) ly[i]+=d;
				//else slack[i]-=d;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(matching[i]!=-1) ans+=w[matching[i]][i];
	return ans ;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			lx[i]=-INF;ly[i]=0;
			for(int j=1;j<=n;j++){
				scanf("%d",&w[i][j]);	
				lx[i]=max(lx[i],w[i][j]);
			}
		}
		printf("%d\n",KM());	
	}
	return 0;
}
