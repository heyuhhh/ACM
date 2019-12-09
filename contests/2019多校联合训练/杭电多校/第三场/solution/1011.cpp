#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m;
struct edge
{
	int to,next,w;
}e[400005];
int cnt;
int head[200005];
void ins(int u,int v,int w)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int f[200005][2];
int fi[200005];
int s[200005][2];
int si[200005];
int t[200005][2];
int ti[200005];
int fa[200005][2];
int ans[200005];
int d[2000005];
void dfs1(int x,int y)
{
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		int w=e[i].w;
		if(v==y) continue;
		d[v]=w;
		dfs1(v,x);
		if(f[v][0]+w>f[x][0])
		{
			t[x][0]=s[x][0];
			ti[x]=si[x];
			s[x][0]=f[x][0];
			si[x]=fi[x]; 
			f[x][0]=f[v][0]+w;
			fi[x]=v;
		}
		else if(f[v][0]+w>s[x][0])
		{
			t[x][0]=s[x][0];
			ti[x]=si[x];
			s[x][0]=f[v][0]+w;
			si[x]=v;
		}
		else if(f[v][0]+w>t[x][0])
		{
			t[x][0]=f[v][0]+w;
			ti[x]=v;
		}
	}
	f[x][1]=min(f[fi[x]][0],max(f[fi[x]][1],s[fi[x]][0])+d[fi[x]]);
	s[x][1]=min(f[si[x]][0],max(f[si[x]][1],s[si[x]][0])+d[si[x]]);
}
void dfs2(int x,int y)
{
	ans[x]=min(max(f[x][0],fa[x][1]),max(max(f[x][1],s[x][0]),fa[x][0]));
	for(int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		int w=e[i].w;
		if(v==y) continue;
		if(fi[x]==v)
		{
			fa[v][0]=max(s[x][0],fa[x][0])+w;
			fa[v][1]=min(fa[v][0]-w,min(max(max(s[x][1],t[x][0]),fa[x][0]),max(s[x][0],fa[x][1]))+w);
		}
		else
		{
			fa[v][0]=max(f[x][0],fa[x][0])+w;
			if(si[x]==v)
				fa[v][1]=min(fa[v][0]-w,min(max(max(f[x][1],t[x][0]),fa[x][0]),max(f[x][0],fa[x][1]))+w);
			else 
				fa[v][1]=min(fa[v][0]-w,min(max(max(f[x][1],s[x][0]),fa[x][0]),max(f[x][0],fa[x][1]))+w);
		}
		dfs2(v,x);
	}
}
int val,pos;
void ini()
{
	for(int i=0;i<=n;i++)
	{
		f[i][0]=0; f[i][1]=0; fi[i]=0;
		s[i][0]=0; s[i][1]=0; si[i]=0;
		t[i][0]=0; t[i][1]=0; ti[i]=0;
		d[i]=0;
		fa[i][0]=0; fa[i][1]=0;
		ans[i]=0;
		head[i]=0;
	}
	cnt=0;
	val=4e8+1,pos;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ini();
		for(int i=1;i<n;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			ins(u,v,w);
			ins(v,u,w);
		}
		dfs1(1,0);
		dfs2(1,0);
	/*	for(int i=1;i<=n;i++)
			printf("%d\n",ans[i]); */
		for(int i=1;i<=n;i++)
		{
		   	if(ans[i]<val)
			{
		    	val=ans[i];
		    	pos=i;
			}
			else if(ans[i]==val&&i<pos)
			{
				pos=i;
			}
		}
		printf("%d %d\n",pos,val);
	}
	return 0;
}



