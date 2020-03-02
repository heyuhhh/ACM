#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int N=310000;
struct bian{
	int next,point;
}b[N<<1];
int p[N],len;
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
int n,father[N][19],m,d[N];
void dfs(int k1,int k2){
	father[k1][0]=k2; d[k1]=d[k2]+1;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2) dfs(j,k1);
	}
}
int getf(int k1,int k2){
	if (d[k1]<d[k2]) swap(k1,k2);
	for (int i=18;i>=0;i--)
		if (d[k1]-d[k2]>=(1<<i)) k1=father[k1][i];
	if (k1==k2) return k1;
	for (int i=18;i>=0;i--)
		if (father[k1][i]!=father[k2][i]){
			k1=father[k1][i]; k2=father[k2][i];
		}
	return father[k1][0];
}
long long A[N],B[N],ans[N];
void dfs2(int k1,int k2){
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			dfs2(j,k1);
			A[k1]+=A[j]; B[k1]+=B[j];
		}
	}
}
void dfs3(int k1,int k2){
	ans[k1]+=A[k1]*d[k1]+B[k1];
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2){
			ans[j]=ans[k1]; dfs3(j,k1);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2);
		add(k1,k2);
	}
	dfs(1,0);
	for (int i=1;i<=18;++i)
		for (int j=1;j<=n;j++)
			father[j][i]=father[father[j][i-1]][i-1];
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2);
		int f=getf(k1,k2); int l=d[k1]+d[k2]-d[f]*2;
		A[k1]-=2; B[k1]+=1+d[k1]*2-l;
		A[k2]-=2; B[k2]+=1+d[k2]*2-l;
		A[f]+=4; B[f]-=(1+d[k1]*2-l)+(1+d[k2]*2-l);
		int x=d[k1]-d[f];
		ans[1]+=1ll*x*(l-x);
	}
	dfs2(1,0); dfs3(1,0);
	for (int i=1;i<=n;i++) printf("%lld\n",ans[i]);
	return 0;
}