#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1005;
int t,n,m;
int f[N];
int find(int x){
	return x==f[x] ? f[x] :f[x]=find(f[x]);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n+1;i++) f[i]=i;
		for(int i=1,x,y;i<=m;i++){
			scanf("%d%d",&x,&y);
			int fx=find(x),fy=find(y);
			f[fx]=fy;
		}
		int ans = 0;
		for(int i=1;i<=n;i++){
			int fi = find(i);
			if(fi==i) ans++;
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
