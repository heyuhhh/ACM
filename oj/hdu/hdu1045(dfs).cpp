#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10 ;
char map[N][N];
int n,ans=0;

inline void init(){
	getchar();ans=0;
}

inline bool judge(int x,int y){
	int flag1 = 1,flag2 = 1;
	for(int i=x-1;i>=1;i--){
		if(map[i][y]=='@'){
			flag1=0;break ;
		}
		if(map[i][y]=='X'){break ;}
	}
	for(int i=y-1;i>=1;i--){
		if(map[x][i]=='X'){break;}
		if(map[x][i]=='@'){
			flag2=0;break ;
		}
	}
	if(flag1 && flag2) return true;
	return false ;
}

inline void dfs(int k,int cnt){
	int x=k/n+1,y=k%n;
	if(y==0) y=n;
	if(k%n==0) x=k/n;
	if(k>n*n){
		ans=max(ans,cnt);
		return ;
	}
	if(map[x][y]=='X')dfs(k+1,cnt);
	if(map[x][y]=='.'){
		if(judge(x,y)){
			map[x][y]='@';
			dfs(k+1,cnt+1);
			map[x][y]='.';
			dfs(k+1,cnt);
		}else{
			dfs(k+1,cnt);
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		init();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) scanf("%c",&map[i][j]);
			getchar();
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
