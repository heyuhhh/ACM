#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int N=110000;
struct bian{
	int next,point;
}b[N<<1];
int p[N],len,n;
void ade(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
int d[N],father[N],imp[N],f[N],g[N],L[N],R[N],ans[N];
vector<int> A;
void getd(int k1,int k2){
	father[k1]=k2; d[k1]=d[k2]+1;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2) getd(j,k1);
	}
}
void dfs(int k1,int k2){
	f[k1]=1; g[k1]=1;
	for (int i=p[k1];i;i=b[i].next){
		int j=b[i].point;
		if (j!=k2&&imp[j]==0){
			dfs(j,k1); g[k1]=max(g[k1],f[k1]+f[j]);
			f[k1]=max(f[k1],f[j]+1);
		}
	}
}
void put(int k1,int k2){
	ans[k1]=max(ans[k1],k2);
	ans[k2]=max(ans[k2],k1);
}
void solve(){
	scanf("%d",&n); len=0;
	for (int i=1;i<=n;i++) p[i]=0;
	for (int i=1;i<=n;i++) ans[i]=0;
	for (int i=1;i<n;i++){
		int k1,k2; scanf("%d%d",&k1,&k2);
		add(k1,k2);
	}
	getd(1,0);
	int u=1;
	for (int i=1;i<=n;i++) if (d[i]>d[u]) u=i;
	getd(u,0); int v=1;
	for (int i=1;i<=n;i++) if (d[i]>d[v]) v=i;
	A.clear();
	for (int i=v;i;i=father[i]) A.push_back(i);
	for (int i=1;i<=n;i++) imp[i]=0,f[i]=0;
	for (int i=0;i<A.size();i++) imp[A[i]]=1;
	for (int i=0;i<A.size();i++) dfs(A[i],0);
	for (int i=0;i<A.size();i++){
		L[i]=i+f[A[i]];
		R[i]=A.size()-i-1+f[A[i]];
	}
	for (int i=1;i<A.size();i++) L[i]=max(L[i],L[i-1]);
	for (int i=1;i<A.size();i++) put(L[i-1],R[i]);
	for (int i=1;i<=n;i++) if (imp[i]==0) put(A.size(),g[i]);
	for (int i=n;i;i--) ans[i-1]=max(ans[i-1],ans[i]);
	long long tot=0;
	for (int i=1;i<=n;i++) tot+=ans[i];
	printf("%lld\n",tot);
}
int main(){
	int t; scanf("%d",&t);
	for (;t;t--) solve();
	return 0;
}