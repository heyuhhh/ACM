#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 1005;
int n,d;
int f[N],vis[N];
struct node{
	int x,y;
}a[N];

bool dist(node A,node B){
	int tmp1 = A.x-B.x,tmp2 = A.y-B.y;
	return tmp1*tmp1+tmp2*tmp2<=d*d;
}

int find(int x){return x==f[x] ? x : f[x]=find(f[x]);}

int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=n+1;i++) f[i]=i;
	getchar();char c;
	while(scanf("%c",&c)!=EOF){
		if(c=='O'){
			int p;scanf("%d",&p);
			vis[p]=1;
			for(int i=1;i<=n;i++){
				if(i==p) continue ;
				if(vis[i] && dist(a[p],a[i])){
					int fp=find(p),fi=find(i);
					f[fp]=fi;
				}
			}
		}else{
			int p1,p2;scanf("%d%d",&p1,&p2);
			int f1=find(p1),f2=find(p2);
			if(f1==f2){
				puts("SUCCESS");
			}else puts("FAIL");
		}
		getchar();
	}
	return 0;
}
