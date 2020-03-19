#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define mem(x) memset(x,0,sizeof(x))
using namespace std;

const int N = 505;
int n,m,p,ans;
char like[N][5],dlike[N][5]; //这里我一开始数组开的是4，WA了，开成5就AC了 
int check[N],match[N],link[N][N];

inline int dfs(int x){
	for(int i=1;i<=p;i++){
		if(link[x][i] && !check[i]){
			check[i]=1;
			if(!match[i] || dfs(match[i])){
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	while(~scanf("%d%d%d",&n,&m,&p)){
		mem(match);mem(link);ans=0;
		for(int i=1;i<=p;i++){
			scanf("%s%s",like[i],dlike[i]);
		}
		for(int i=1;i<=p;i++)
			for(int j=1;j<=p;j++)
				if(strcmp(like[i],dlike[j])==0 || strcmp(like[j],dlike[i])==0) link[i][j]=1;
		for(int i=1;i<=p;i++){
			mem(check);
			if(dfs(i)) ans++;
		}
		printf("%d\n",p-ans/2);
	}
	return 0;
}
/*
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define mem(x) memset(x,0,sizeof(x))
using namespace std;

const int N = 505 ,M = 205;
int n,m,p,ans;
int check[N],match[N],like[N][M],dlike[N][M],link[N][N];

inline int dfs(int x){
	for(int i=1;i<=p;i++){
		if(link[x][i] && !check[i]){
			check[i]=1;
			if(!match[i] || dfs(match[i])){
				match[i]=x;
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	while(~scanf("%d%d%d",&n,&m,&p)){
		mem(match);mem(like);mem(dlike);mem(link);ans=0;
		getchar();
		for(int i=1;i<=p;i++){
			int n1,n2;char x,y,tmp;
			scanf("%c%d%c%c%d",&x,&n1,&tmp,&y,&n2);getchar();
				if(x=='C') like[i][n1]=1;
				else like[i][n1+n]=1;
				if(y=='C') dlike[i][n2]=1;
				else dlike[i][n2+n]=1;
		}
		for(int i=1;i<=p;i++){
			for(int j=1;j<=2*n;j++){
				if(like[i][j]){
					for(int k=1;k<=p;k++){
						if(k==i) continue ;
						if(dlike[k][j]) link[i][k]=link[k][i]=1;
					}
				}
			}
		}
		for(int i=1;i<=p;i++){
			mem(check);
			if(dfs(i)) ans++;
		}
		printf("%d\n",p-ans/2);
	}
	return 0;
}
*/
