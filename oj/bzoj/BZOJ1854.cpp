#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 5;
int n;
int f[N],vis[N];

inline int find(int x){return f[x]==x ? f[x] : f[x] = find(f[x]);}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++) f[i]=i;
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		int fx = find(x),fy = find(y);
		if(fx==fy) vis[fx]=1;
		else{
			if(fx>fy) swap(fx,fy);
			f[fx]=fy;
			if(vis[fx]) vis[fy]=1;
			else vis[fx]=1;	
		}
	}
	for(int i=1;i<=n+1;i++){
		if(!vis[i]){
			cout<<i-1;
			break ;
		}
	}
	return 0 ; 
} 
