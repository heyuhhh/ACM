#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1505 ;	
int n,p1,p2,cnt;
int f[N],dp[N][N],v[N],g[N],set[N][5];

int find(int x){
	if(f[x]==x) return x;
	int tmp = f[x];
	f[x]=find(f[x]);
	v[x]=(v[x]+v[tmp])%2;
	return f[x];
}

int main(){
	while(~scanf("%d%d%d",&n,&p1,&p2)){
		if(!n && !p1 &&!p2) break;
		cnt = 0;memset(set,0,sizeof(set));memset(dp,0,sizeof(dp)); 
		memset(f,-1,sizeof(f));
		for(int i=1;i<=p1+p2;i++) f[i]=i,v[i]=0;
		char s[10];int x,y;
		for(int k=1;k<=n;k++){
			scanf("%d%d %s",&x,&y,s);
			int fx=find(x),fy=find(y);
			if(fx==fy) continue ;
			f[fx]=fy;
			if(s[0]=='y') v[fx]=(v[x]+v[y])%2;
			else v[fx]=(v[x]+v[y]+1)%2;
		}
		for(int i=1;i<=p1+p2;i++){
			if(find(i)==i) g[i]=++cnt;
		}
		for(int i=1;i<=p1+p2;i++) set[g[find(i)]][v[i]]++;//set数组记录第几组两类的个数 
		dp[0][0]=1;//dp[i,j]前i个集合，和为j的情况数量 
		for(int i=1;i<=cnt;i++){
			for(int j=0;j<=p1;j++){  //注意p1等于0的情况 
				if(j>=set[i][0]) dp[i][j]+=dp[i-1][j-set[i][0]]; 
				if(j>=set[i][1]) dp[i][j]+=dp[i-1][j-set[i][1]];
			}
		} 
		int tmp = p1;
		int choose[N];
		memset(choose,-1,sizeof(choose));
		if(dp[cnt][p1]==1){
			for(int i=cnt;i>=1;i--){
				if(dp[i-1][tmp-set[i][0]]==dp[i][tmp]){
					choose[i]=0;
					tmp-=set[i][0];
				}else if(dp[i-1][tmp-set[i][1]]==dp[i][tmp]){
					choose[i]=1;
					tmp-=set[i][1];
				}
			}
			for(int i=1;i<=p1+p2;i++){
				if(choose[g[find(i)]]==v[i]) printf("%d\n",i);
			}
			puts("end");
		}else puts("no");
	}
	return 0;
}
/*
2 0 2
1 2 yes
2 1 yes 
*/ 
