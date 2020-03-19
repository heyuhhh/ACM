#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define mem(x) memset(x,0,sizeof(x))
using namespace std;

const int N = 1005 ,M = 505;
int n,m,ans,mid;
int vy[N],linky[M][N],link[N][M],check[N];

inline int dfs(int x){
	for(int i=0;i<m;i++){
		if(link[x][i] && !check[i]){
			check[i]=1;
			if(vy[i]<mid){
				linky[i][++vy[i]]=x;
				return 1;
			}else{
				for(int j=1;j<=vy[i];j++){
					int now = linky[i][j];
					if(dfs(now)){
						linky[i][j]=x;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

inline int Check(int x){
	mem(linky);mem(vy);
	for(int i=1;i<=n;i++){
		mem(check);
		if(!dfs(i)) return 0;
	}
	return 1;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		if(!n && !m) break;
		mem(link);ans=0;
		for(int i=1;i<=n;i++){
			char s[20];
			scanf("%s",s);
			while(true){
				int x;char tmp;
				scanf("%d%c",&x,&tmp);
				link[i][x]=1;
				if(tmp=='\n') break ;
			}
		}
		int l=1,r=1001,Ans=0x3f3f3f;
		while(l<=r){
			mid=l+r>>1;
			if(Check(mid)){
				r=mid-1;
				Ans=mid;
			}else l=mid+1;
		}
		printf("%d\n",Ans);
	}
	return 0;
}
