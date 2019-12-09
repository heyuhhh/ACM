#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <cmath>
#include <math.h>
using namespace std;
double pi=acos(-1);
#define mod 1000000007
#define inf 0x3fffffff
long long int a[200010],number[200010<<2],number2[200010<<2],bz[200010<<2],bz2[200010<<2];
struct node
{
	int id;
	long long int b;
	/* data */
} no[200010];
bool cmp(const node &fi,const node &se)
{
	if(fi.b==se.b) return fi.id<se.id;
	return fi.b<se.b;
}
int to[200010];
void PushUp(int rt)
{
	number[rt]=number[rt*2];
	if(number[rt*2+1]>number[rt]) number[rt]=number[rt*2+1];
}

void build(int l,int r,int rt)
{
	bz[rt]=0;
	number[rt]=0;
	bz2[rt]=0;
	if(l==r)
    {
		number[rt]=0;
		number2[rt]=0;
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,rt*2);
	build(mid+1,r,rt*2+1);
	PushUp(rt);
}
void pushdown(int rt,int l,int r)
{
	int mid=(l+r)/2;
    if (bz[rt])
    {
        bz[rt*2]+=bz[rt];
        bz[rt*2+1]+=bz[rt];
        number[rt*2]+=(bz[rt]);
        number[rt*2+1]+=(bz[rt]);
        bz[rt]=0;
    }
    if(bz2[rt])
    {
        bz2[rt*2]+=bz2[rt];
        bz2[rt*2+1]+=bz2[rt];
        number2[rt*2]+=(bz2[rt]);
        number2[rt*2+1]+=(bz2[rt]);
        bz2[rt]=0;
    }
}
void change(long long int o,int L,int R,int l,int r,int rt)
{
	if(L>R) return;
	if(l==r)
    {
		number[rt]+=o;
		number2[rt]+=1;
		return;
	}
	if(L<=l&&R>=r)
    {
		number[rt]+=o;
		bz[rt]+=o;
		bz2[rt]+=1;
		return;
	}
	int mid=(l+r)/2;
	pushdown(rt,l,r);
	if(L<=mid) change(o,L,R,l,mid,rt*2);
	if(R>mid) change(o,L,R,mid+1,r,rt*2+1);
	PushUp(rt);
}
long long int query(long long int k,int l,int r,int rt)
{
	if(l==r) return number2[rt];
	int mid=(l+r)/2;
	pushdown(rt,l,r);
	int ans;
	if(number[rt*2]>k) ans=query(k,l,mid,rt*2);
	else ans=query(k,mid+1,r,rt*2+1);
	PushUp(rt);
	return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
 	int n=1,m=1;
 	scanf("%d %d",&n,&m);
 	build(1,n+1,1);
 	for(int i=1;i<=n;i++)
    {
 		scanf("%lld",&a[i]);
 		no[i].b=a[i];
 		no[i].id=i;
 	}
 	sort(no+1,no+n+1,cmp);
 	change(1e9,n+1,n+1,1,n+1,1);
 	for(int i=1;i<=n;i++)
 		to[no[i].id]=i;
 	for(int i=1;i<=n;i++)
 	{
 		long long int k=query(m-a[i],1,n+1,1);
 		printf("%lld ",i-k);
 		change(a[i],to[i],n+1,1,n+1,1);
 	}
 	printf("\n");
    }
	return 0;
}
