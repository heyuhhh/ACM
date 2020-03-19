#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 150005;
int f[N];
int n,k,ans;

int find(int x){return f[x]==x ? x : f[x]=find(f[x]);}

bool same(int x,int y){
	return find(x)==find(y);
}

void Union(int x,int y){
	int fx=find(x),fy=find(y);
	f[fx]=fy;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=3*n+1;i++) f[i]=i;
	while(k--){
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(x<1 || y<1 ||x>n ||y>n){
			ans++;continue ;
		}
		int fx=find(x),fy=find(y);
		if(op==1){
			if(same(x,y+n) ||same(x,y+2*n)){
				ans++;continue;
			}
			Union(x,y);Union(x+n,y+n);Union(x+2*n,y+2*n);
		}else{
			if(same(x,y) || same(x,y+2*n)){
				ans++;continue ;
			}
			Union(x,y+n);Union(x+n,y+2*n);Union(x+2*n,y);
		}
	}
	printf("%d",ans);
	return 0;
}
