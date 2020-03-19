#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define mem(x) memset(x,0,sizeof(x))
#define INF 10000000
using namespace std;

const int N = 305;
int k,c,m;
int mid,ylink[N][N],vy[N],check[N],d[N][N];

inline int dfs(int x){
	for(int i=1;i<=k;i++){
		if(!check[i]){
			if(d[x][i]<=mid) check[i]=1;
			else continue ;
			if(vy[i]<m){
				ylink[i][++vy[i]]=x;
				return 1;
			}
			for(int j=1;j<=vy[i];j++){
				int now = ylink[i][j];
				if(dfs(now)){
					ylink[i][j]=x;
					return 1;
				}
			}
		}
	}
	return 0;
}

inline int Check(int x){
	mem(vy);mem(ylink);
	for(int i=k+1;i<=k+c;i++){
		mem(check);
		if(!dfs(i)) return 0;
	}
	return 1;
}

int main(){
	scanf("%d%d%d",&k,&c,&m);
	for(int i=1;i<=k+c;i++) for(int j=1;j<=k+c;j++) scanf("%d",&d[i][j]);
	for(int i=1;i<=k+c;i++)
		for(int j=1;j<=k+c;j++)
			if(i!=j &&!d[i][j]) d[i][j]=INF;
	for(int t=1;t<=k+c;t++)for(int i=1;i<=k+c;i++)for(int j=1;j<=k+c;j++)
		if(d[i][j]>d[i][t]+d[t][j]) d[i][j]=d[i][t]+d[t][j];
	for(int i=1;i<=k;i++){
		for(int j=k+1;j<=k+c;j++){
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	int l=1,r=INF+1,Ans;
	while(l<=r){
		mid=l+r>>1;
		if(Check(mid)){
			r=mid-1;
			Ans=mid;
		}else l=mid+1; 
	}
	printf("%d\n",Ans);
	return 0;
}
