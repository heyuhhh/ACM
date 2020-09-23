#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 2000000
using namespace std;
const int mod=998244353,g=3;
int rv[MAX+5],invr[MAX+5];
struct poly
{
	vector<int>x;
	int deg=0;
	poly(){deg=0,x.resize(1);}
};
int M(int x){return x>=mod?x-mod:x;}
int mypow(int a,int b)//������ 
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void precalc_invr()//����ɸ��Ԫ 
{
	int i;
	invr[1]=1;
	for(i=2;i<=MAX;i++)invr[i]=M(-1LL*invr[mod%i]*(mod/i)%mod+mod);
}
poly add(poly a,poly b)//����ʽ�ӷ� 
{
	int i;
	poly nw;
	nw.deg=max(a.deg,b.deg);
	nw.x.resize(nw.deg+1);
	for(i=0;i<=a.deg;i++)nw.x[i]+=a.x[i];
	for(i=0;i<=b.deg;i++)nw.x[i]+=b.x[i];
	for(i=0;i<=nw.deg;i++)nw.x[i]=M(nw.x[i]);
	return nw;
}
poly Minus(poly a,poly b)//����ʽ���� 
{
	int i;
	poly nw;
	nw.deg=max(a.deg,b.deg);
	nw.x.resize(nw.deg+1);
	for(i=0;i<=a.deg;i++)nw.x[i]+=a.x[i];
	for(i=0;i<=b.deg;i++)nw.x[i]-=b.x[i];
	for(i=0;i<=nw.deg;i++)nw.x[i]=M(nw.x[i]+mod);
	return nw;
}
poly ext(poly a,int siz)//����ʽ���������ɱ䳤������̺��Ը�λ�� 
{
	int i,tp;
	poly nw;
	nw.deg=siz;
	nw.x.resize(siz+1);
	tp=min(siz,a.deg);
	for(i=0;i<=tp;i++)nw.x[i]=a.x[i];
	return nw;
}
poly reverse(poly a)//����ʽ��ת
{
	int i;
	poly nw;
	nw.deg=a.deg;
	nw.x.resize(nw.deg+1);
	for(i=0;i<=nw.deg;i++)nw.x[i]=a.x[nw.deg-i];
	return nw;
}
poly dot(poly a,poly b)//����ʽ��� 
{
	int i;
	poly nw;
	nw.deg=min(a.deg,b.deg);
	nw.x.resize(nw.deg+1);
	for(i=0;i<=nw.deg;i++)nw.x[i]=1LL*a.x[i]*b.x[i]%mod;
	return nw;
}
poly scalar_mul(poly a,int k)//����ʽ���� 
{
	int i;
	poly nw;
	nw.deg=a.deg;
	nw.x.resize(nw.deg+1);
	for(i=0;i<=nw.deg;i++)nw.x[i]=1LL*a.x[i]*k%mod;
	return nw;
}
poly der(poly a)//����ʽ�� 
{
	int i;
	poly nw;
	nw.deg=max(0,a.deg-1);
	nw.x.resize(nw.deg+1);
	for(i=1;i<=a.deg;i++)nw.x[i-1]=1LL*a.x[i]*i%mod;
	return nw;
}
poly integ(poly a)//����ʽ���� 
{
	int i;
	//precalc_invr()
	poly nw;
	nw.deg=a.deg+1;
	nw.x.resize(nw.deg+1);
	for(i=0;i<=a.deg;i++)nw.x[i+1]=1LL*a.x[i]*invr[i+1]%mod;
	return nw;
}
void dft(poly *a,int type,int limit)//DFT/IDFT 
{
    int wn,w,mid,u,v,rr,i,j,k;
    for(i=1;i<limit;i++)if(rv[i]>i)swap(a->x[rv[i]],a->x[i]);
    for(mid=1;mid<limit;mid<<=1)
    {
        wn=(type==1)?mypow(g,(mod-1)/2/mid):mypow(g,mod-1-(mod-1)/2/mid);
        for(j=0,rr=mid<<1;j<limit;j+=rr)
        {
            w=1;
            for(k=0;k<mid;k++,w=1LL*w*wn%mod)
            {
                u=a->x[j+k],v=1LL*w*a->x[j+mid+k]%mod;
                a->x[j+k]=M(u+v);
                a->x[j+mid+k]=M(u-v+mod);
            }
        }
    }
    if(type==-1)
    {
        int inv=mypow(limit,mod-2);
        for(i=0;i<limit;i++)a->x[i]=1LL*inv*a->x[i]%mod;
    }
}
poly mul(poly a,poly b)//����ʽ�˷� 
{
	int limit=1,l=0,i,n,m;
	n=a.deg;m=b.deg;
	poly f,g;
	while(limit<=n+m)limit<<=1,l++;
    for(i=1;i<limit;i++)rv[i]=(rv[i>>1]>>1)|((i&1)<<(l-1));
    f=ext(a,limit-1);
    g=ext(b,limit-1);
    dft(&f,1,limit);
    dft(&g,1,limit);
    for(i=0;i<limit;i++)f.x[i]=1LL*f.x[i]*g.x[i]%mod;
    dft(&f,-1,limit);
	f.deg=n+m;f.x.resize(n+m+1);
	return f;
}
poly poly_inv(poly a,int n)//����ʽ���棬mod x^n,Ҫ��������� 
{
	int i,seq[21],cnt=0;
	poly h,f[21];
	while(n!=1)f[++cnt]=ext(a,n-1),seq[cnt]=n,n=n/2+(n&1);
	h.x[0]=mypow(a.x[0],mod-2);
	for(i=cnt;i>0;i--)h=Minus(scalar_mul(h,2LL),ext(mul(ext(mul(f[i],h),seq[i]-1),h),seq[i]-1));
	return h;
}
poly poly_ln(poly a,int n)//����ʽȡln��mod x^n,Ҫ������Ϊ1 
{
	poly f;
	f=der(a);
	f=integ(ext(mul(f,poly_inv(a,n)),n-1));
	f.deg=n-1;
	f.x.resize(n);
	return f;
}
poly poly_exp(poly a,int n)//����ʽexp��mod x^n,��֤������Ϊ0 
{
	int i,seq[21],cnt=0;
	poly h,f[21];
	while(n!=1)f[++cnt]=ext(a,n-1),seq[cnt]=n,n=n/2+(n&1),f[cnt].x[0]=1;
	h.x[0]=1;
	for(i=cnt;i>0;i--)h=ext(mul(h,Minus(f[i],poly_ln(h,seq[i]))),seq[i]-1);
	return h;
} 
void poly_div(poly a,poly b,poly *q,poly *r)//����ʽ������qΪ��,rΪ���� ��֤b��Ϊ�����ʽ 
{
	int n,m;
	n=a.deg;m=b.deg;
	if(n<m)
	{
		q->x.resize(1);q->deg=0;q->x[0]=0;
		*r=a;
	}
	*q=reverse(ext(mul(reverse(a),poly_inv(reverse(b),n-m+1)),n-m));
	*r=Minus(a,mul(*q,b)); 
} 
poly poly_sqrt(poly a,int n)//����ʽ��������֤������Ϊ1,�������Ϊ1ʱ��Ҫ����ʣ�� 
{
	int i,seq[21],cnt=0,inv2;
	inv2=mypow(2,mod-2);
	poly h,f[21];
	while(n!=1)f[++cnt]=ext(a,n-1),seq[cnt]=n,n=n/2+(n&1),f[cnt].x[0]=1;
	h.x[0]=1;
	for(i=cnt;i>0;i--)h=add(ext(mul(f[i],poly_inv(scalar_mul(h,2),seq[i])),seq[i]),scalar_mul(h,inv2));
	return h;
} 
poly poly_pow(poly a,int m,int n)//����ʽ�ݴ�a^mmodx^n�������������汾
{
	int i,np,tp,inv,tmp;
	poly f,g;
	np=a.deg;
	for(i=0;i<=np&&a.x[i]==0;i++);
	tp=i;
	if(i>n)return f;
	inv=mypow(a.x[tp],mod-2);
	tmp=mypow(a.x[tp],m);
	g.deg=np-tp;g.x.resize(g.deg+1);
	for(i=0;i<=g.deg;i++)g.x[i]=1LL*inv*a.x[i+tp]%mod;
	g=poly_exp(scalar_mul(poly_ln(g,n),m),n);
	f.x.resize(n); f.deg=n-1;
	for(i=0;i<=g.deg&&1LL*i+1LL*m*tp<=f.deg;i++)f.x[i+m*tp]=1LL*tmp*g.x[i]%mod;
	return f;
}
int fac[100005],T;
int main()
{
	freopen("1.in","r",stdin);
	freopen("233.out","w",stdout);
	int n=100000;
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	poly f;
	precalc_invr();
	f=ext(f,n);
	f.x[0]=1;
	for(int i=1;i<=n;i++)f.x[i]=1ll*f.x[i-1]*(i+invr[i])%mod;
	f=poly_sqrt(f,n+1);
	for(int i=1;i<=n;i++)f.x[i]=1ll*f.x[i]*fac[i]%mod;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		printf("%d\n",f.x[n]);
	}
	/*
	printf("\n");
	for(i=0;i<m;i++)printf("%d ",g.x[i]);*/
	/*
	int n,m,i;
	poly a,b,f;
	scanf("%d%d",&n,&m);
	a=ext(a,n);b=ext(b,m);
	for(i=0;i<=n;i++)scanf("%d",&a.x[i]);
	for(i=0;i<=m;i++)scanf("%d",&b.x[i]);
	f=mul(a,b);
	for(i=0;i<=n+m;i++)printf("%d ",f.x[i]);
	*/
	return 0;	
} 
