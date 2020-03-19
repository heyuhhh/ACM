#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define mem(x) memset(x,0,sizeof(x))
using namespace std;

const int N = 1005 , M = 25;
int n,b,mid;
int vy[M],ylink[M][N],link[N][M],c[M],check[M];

inline int dfs(int x,int l,int r){
	for(int i=l;i<=r;i++){
		int u = link[x][i];
		if(!check[u]){
			check[u]=1;
			if(vy[u]<c[u]){
				ylink[u][++vy[u]]=x;
				return 1;
			}
			for(int j=1;j<=vy[u];j++){
				int now = ylink[u][j];
				if(dfs(now,l,r)){
					ylink[u][j]=x;
					return 1;
				}
			}
		}
	}
	return 0;
}

inline int Check(int range){
	bool flag ;
	for(int i=1;i+range-1<=b;i++){
		mem(vy);mem(ylink);	
		flag=true ;
		for(int j=1;j<=n;j++){
			mem(check);
			if(!dfs(j,i,i+range-1)){
				flag=false;
				break ;
			}
		}
		if(flag) return 1;
	}
	return flag;
}

int main(){
	scanf("%d%d",&n,&b);;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=b;j++) scanf("%d",&link[i][j]);
	for(int i=1;i<=b;i++) scanf("%d",&c[i]);
	int l=1,r=b<<1,Ans;
	while(l<=r){
		mid=l+r>>1;
		if(Check(mid)){		
			r=mid-1;Ans=mid;
		}else l=mid+1;
	}
	printf("%d",Ans);
	return 0;
}
