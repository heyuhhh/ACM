#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 1007
#define MAXM (MAXN*MAXN*2)
int hd[MAXN], nxt[MAXM], to[MAXM], le[MAXM], en;
int fa[MAXN]; bool used[MAXN];
int n,m;
inline void adde(int a, int b, int v) {
	nxt[en]=hd[a]; to[en]=b; hd[a]=en; le[en]=v; en++;
}
inline int findfa(int x) {
	int f=x, t;
	while(fa[f]!=f) {
		f=fa[f];
	}
	while(x!=f) {
		t=fa[x];
		fa[x]=f;
		x=t;
	}
	return f;
}
int d1[MAXN], d2[MAXN];
int dfs1(int x) {
	int ans=0;
	used[x]=1;
	for(int i=hd[x]; ~i; i=nxt[i]) {
		int t=to[i], v=le[i];
		if(v!=-1) continue;
		if(!used[t])dfs1(t);
		ans = max(ans, d1[t]+1);
	}
	d1[x]=ans;
	return ans;
}
int dfs2(int x) {
	int ans=0;
	used[x]=1;
	for(int i=hd[x]; ~i; i=nxt[i]) {
		int t=to[i], v=le[i];
		if(v!=1) continue;
		if(!used[t]) dfs2(t);
		ans = max(ans, d2[t]+1);
	}
	d2[x]=ans;
	return ans;
}
int f[MAXN], t[MAXN], vv[MAXN];
int main() {
#ifndef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	en=0; memset(hd,-1,sizeof hd);
	memset(used,0,sizeof used);
	for(int i=1; i<=n; i++) fa[i]=i;
	for(int i=0; i<m; i++) {
		int a,b; char c; scanf("%d%c%d", &a, &c, &b);
		f[i]=a, t[i]=b; vv[i]=c;
		switch(c) {
			case '=':
				int f1=findfa(a), f2=findfa(b);
				fa[f1]=f2;
				break;
		}
	}
	for(int i=0; i<m; i++) {
		int a=f[i], b=t[i], c=vv[i];
		int f1=findfa(a), f2=findfa(b);
		switch(c) {
			case '<':
				adde(f1, f2, -1);
				adde(f2, f1, 1);
				break;
			case '>':
				adde(f1, f2, 1);
				adde(f2, f1, -1);
				break;
		}
	}
	memset(used,0,sizeof used);
	for(int i=1; i<=n; i++) if(findfa(i)==i) {
		if (!used[i]) dfs1(i);
	}
	memset(used,0,sizeof used);
	for(int i=1; i<=n; i++) if(findfa(i)==i) {
		if (!used[i]) dfs2(i);
	}
	for(int i=1; i<=n; i++) {
		int f=findfa(i);
		if(d1[f]==2) putchar('B');
		else if(d1[f]==1 && d2[f]==1) putchar('R');
		else if(d2[f]==2) putchar('W');
		else putchar('?');
	}
}
