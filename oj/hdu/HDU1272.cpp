#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 100005;
int f[N],v[N];
int find(int x){
	return f[x]==x ? x : f[x]=find(f[x]);
}
int main(){
	bool end=false;
	while(1){
		int x,y,tot=0;
		memset(v,0,sizeof(v));
		bool flag=true;
		for(int i=1;i<=N-5;i++) f[i]=i;
		while(scanf("%d%d",&x,&y)){
			if(x==-1 && y==-1){
				end=true;break;
			}
			if(!x && !y) break;
			v[x]++;v[y]++;tot++;
			int fx=find(x),fy=find(y);
			if(fx==fy) flag=false;
			f[fx]=fy;
		}
		if(end) break;
		int cnt =0;
		for(int i=1;i<=N-5;i++){
			if(v[i] &&f[i]==i)cnt++;
		}
		if((cnt==1 &&flag) || !tot) puts("Yes");
		else puts("No");
	}
	return 0;
}
