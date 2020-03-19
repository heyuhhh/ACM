#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
const int N = 200005 ;
ll f[N],sum[N];
int t,n,m;

int find(int x){
	if(f[x]==x) return x;
	int tmp = f[x];
	f[x]=find(f[x]);
	sum[x]+=sum[tmp];
	return f[x];
}

int main(){
	while(~scanf("%d%d",&n,&m)){
	memset(sum,0,sizeof(sum));
		for(int i=0;i<=n+1;i++) f[i]=i;	
		int ans = 0;
		for(int i=1,x,y,w;i<=m;i++){
			scanf("%d%d%d",&x,&y,&w);y++;
			int fx = find(x),fy=find(y);
			if(fx==fy){
				if(sum[y]-sum[x]!=w) ans++;
			}else{
				f[fy]=fx;
				sum[fy]=sum[x]-sum[y]+w;
			}
		}
		printf("%d\n",ans);		
	}
	return 0;
}
