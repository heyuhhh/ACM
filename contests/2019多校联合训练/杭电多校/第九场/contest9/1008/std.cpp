#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N=110000,M=29;
struct tree{
	int l,r,size;
}t[N*70];
int n,A[N],B[N],root[2],len;
long long all=0;
int getnew(){
	len++; t[len]=(tree){0,0,0}; return len;
}
void insert(int k1,int d,int w){
	t[k1].size+=1; if (d<0) return;
	if (w&(1<<d)){
		if (t[k1].r==0) t[k1].r=getnew();
		insert(t[k1].r,d-1,w);
	} else {
		if (t[k1].l==0) t[k1].l=getnew();
		insert(t[k1].l,d-1,w);
	}
}
long long getans(int k1,int k2,int d,int w){
	if (t[k1].size==0||t[k2].size==0) return 0;
	all+=t[k1].size+t[k2].size;
	if (d==-1){
		int num=min(t[k1].size,t[k2].size);
		t[k1].size-=num; t[k2].size-=num;
		return 1ll*num*w;
	}
	long long tot=getans(t[k1].l,t[k2].r,d-1,w+(1<<d))+getans(t[k1].r,t[k2].l,d-1,w+(1<<d));
	tot+=getans(t[k1].l,t[k2].l,d-1,w)+getans(t[k1].r,t[k2].r,d-1,w);
	t[k1].size=t[t[k1].l].size+t[t[k1].r].size;
	t[k2].size=t[t[k2].l].size+t[t[k2].r].size;
	return tot;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	for (int i=1;i<=n;i++) scanf("%d",&B[i]);
	len=0; root[0]=getnew(); root[1]=getnew();
	for (int i=1;i<=n;i++) insert(root[0],M,A[i]);
	for (int i=1;i<=n;i++) insert(root[1],M,B[i]);
	printf("%lld\n",getans(root[0],root[1],M,0));
}
int main(){
	int t; scanf("%d",&t);
	for (;t;t--) solve();
	return 0;
}