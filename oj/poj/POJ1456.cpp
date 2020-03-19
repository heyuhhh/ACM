#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 10005; 
int f[N];
int n;

struct node{
	int p,d;
	bool operator < (const node &A)const{
		return A.p<p;
	}
}a[N];
int find(int x){return f[x]==x ? f[x] : f[x]=find(f[x]);}
int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=10000;i++) f[i]=i;
		for(int i=1;i<=n;i++) scanf("%d%d",&a[i].p,&a[i].d);
		sort(a+1,a+n+1);
		int ans = 0;
		for(int i=1;i<=n;i++){
			int fd = find(a[i].d);
			if(fd>0){
				ans+=a[i].p;
				f[fd]=fd-1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
