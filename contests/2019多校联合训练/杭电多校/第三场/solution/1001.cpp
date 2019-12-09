#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn=400+5;
const double eps=1e-10;

int n,g,r;
struct pointt{
    long long x,y;
    pointt (long long X=0,long long Y=0)
   	{
       x=X,y=Y;
    }
}p[maxn],c[maxn],ch[maxn];
int f[maxn][maxn],m,cas;
bool vis[maxn][maxn];
bool mp[maxn][maxn];
struct line
{
    pointt a,b;
};

pointt operator + (pointt a,pointt b)  {return pointt(a.x+b.x,a.y+b.y);}
pointt operator - (pointt a,pointt b)  {return pointt(a.x-b.x,a.y-b.y);}
long long operator * (pointt a,pointt b)  {return a.x*b.x+a.y*b.y;}
long long operator ^ (pointt a,pointt b)  {return a.x*b.y-a.y*b.x;}

double dis(const pointt&a,const pointt&b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(pointt a,pointt b)
{
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
long long cross(pointt A,pointt B)
{
    return A.x*B.y-A.y*B.x;
}


bool check(line l,pointt p)
{
    pointt ab=l.b-l.a;
    pointt ba=l.a-l.b;
    if((ab*(p-l.a))<0)
        return dis(p,l.a)<=r+eps;
    if((ba*(p-l.b))<0)
        return dis(p,l.b)<=r+eps;
    long long kk=(l.b-l.a)^(p-l.a);
    if(kk<0) kk=kk*(-1);
    return kk/dis(l.a,l.b)<=r+eps;
}

bool solve(pointt a,pointt b)
{
    for(int i=1;i<=g;i++)
	{
		if(check((line){a,b},c[i])) return 0;
    } 
	return 1;
}

int dp(int l,int r)
{
    if(l==r||vis[l][r]) return f[l][r];
    vis[l][r]=1;
    for(int kk=l+1;kk<r;kk++)
        f[l][r]=max(f[l][r],dp(l,kk)+dp(kk,r));
    f[l][r]+=mp[l][r];
    return f[l][r];
}

void ConvexHull()
{
    m=0;
    for(long long i=0;i<n;++i){
        while(m>1&&cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++]=p[i];
    }
    long long k=m;
    for(long long i=n-2;i>=0;--i){
        while(m>k&&cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
} 

int main()
{
	freopen("1.in","r",stdin);
	freopen("2.out","w",stdout);
    cin>>cas;
    //cas=1;
    for(int t=1;t<=cas;t++)
	{
    	memset(f,0,sizeof(f));
		memset(mp,0,sizeof(mp)); 
		memset(vis,0,sizeof(vis));
		memset(p,0,sizeof(p));
		memset(ch,0,sizeof(ch)); 
		scanf("%d%d%d",&n,&g,&r);
		m=0;
  	  	for(int i=0;i<n;i++)
		{
			scanf("%lld%lld",&p[i].x,&p[i].y);
		} 
 	  	sort(p,p+n,cmp);
	    ConvexHull();
  		for(int i=1;i<=g;i++)
		{
			scanf("%lld%lld",&c[i].x,&c[i].y);
		} 
		for(int i=0;i<m;i++)
		{	
        	for(int j=i+2;j<m;j++)
			{
            	if(i==0&&j==m-1) continue;
            	if(solve(ch[i],ch[j]))
            		mp[i+1][j+1]=1;
            	else mp[i+1][j+1]=0;
        	}
    	}
    	printf("%d\n",dp(1,m));
	}
    return 0;
}
