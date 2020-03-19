#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2505;
int n,m;
int f[N],a[N],b[N],v[N],ans[N];
char c[N];

int find(int x){
	if(x==f[x]) return x;
	int tmp=f[x];
	f[x]=find(f[x]);
	v[x]=(v[x]+v[tmp])%3;
	return f[x];
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=m;i++) scanf("%d%c%d",&a[i],&c[i],&b[i]);
		int tot = 0,cnt = 0,l = 0;
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++){
			bool flag=true;cnt=0;
			for(int j=0;j<=n;j++) f[j]=j,v[j]=0;
			for(int j=1;j<=m;j++){
				if(a[j]==i || b[j]==i) continue;
				int fx=find(a[j]),fy=find(b[j]);
				if(c[j]=='>'){
					if(fx==fy && (v[a[j]]+3-v[b[j]])%3!=2) flag=false,cnt=j;
					else{
						f[fx]=fy;
						v[fx]=(3-v[a[j]]+2+v[b[j]])%3;
					}
				}else if(c[j]=='<'){
					if(fx==fy && (v[a[j]]+3-v[b[j]])%3!=1) flag=false,cnt=j;
					else{
						f[fx]=fy;
						v[fx]=(3-v[a[j]]+1+v[b[j]])%3;
					}					
				}else{
					if(fx==fy && (v[a[j]]+3-v[b[j]])%3!=0) flag=false,cnt=j;
					else{
						f[fx]=fy;
						v[fx]=(3-v[a[j]]+v[b[j]])%3;
					}
				}
				if(!flag) break;
			}
			if(flag) ans[++tot]=i;
			l=max(l,cnt);
		}
		if(tot==0) puts("Impossible");
		else if(tot>1) puts("Can not determine");
		else printf("Player %d can be determined to be the judge after %d lines\n",ans[1],l);
	}
	return 0;
}
