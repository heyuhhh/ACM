#include<stdio.h>
#include<algorithm>
#include<cstring>
#define N 500005
using namespace std;
long long i,j,k,l,s,n,m,tot,vis[N],f[N],L,g[N],b[N],test,K;
long long Q[N],TOT;
long long ans;
struct node1 {
    long long x,y,st;
}q[N];
struct node {
    long long rank[N],su[N],height[N],t[N][35],T[N],last[N];
    char c[N];
    inline void sa() {
        memset(f,0,sizeof(f));
        memset(rank,0,sizeof(rank));
        for (long long i=1;i<=L;i++) f[c[i]-96]++;
        for (long long i=1;i<=30;i++) f[i]+=f[i-1];
        for (long long i=1;i<=30;i++) T[i]=f[i-1]+1;
        for (long long i=1;i<=L;i++) su[++f[c[i]-97]]=i,rank[i]=T[c[i]-96];
        for (long long l=1;l<=L;l*=2) {
            long long r=0;
            memset(f,0,sizeof(f));
            for (long long i=1;i<=L;i++) last[i]=-1,T[i]=0;
            for (long long i=L;i>L-l;i--) q[++r].st=i,q[r].x=rank[i],q[r].y=0,f[q[r].x]++;
            for (long long i=1;i<=L;i++) {
                if (su[i]<=l) continue;
                q[++r].st=su[i]-l,q[r].x=rank[su[i]-l],q[r].y=rank[su[i]];
                f[q[r].x]++;
            }
            for (long long i=1;i<=L;i++) f[i]+=f[i-1];
            for (long long i=1;i<=r;i++) {
                if (last[q[i].x]!=q[i].y) last[q[i].x]=q[i].y,T[q[i].x]=++f[q[i].x-1];
                else ++f[q[i].x-1];
                su[f[q[i].x-1]]=q[i].st; rank[q[i].st]=T[q[i].x];
            }
        }
    }            
    inline void geth() {
        k=0;
        for (long long i=1;i<=L;i++) {
            k--; if (k<0) k=0;
            long long j=su[rank[i]-1]+k,ii=i+k;
            if (rank[i]>1)
            while (c[ii]==c[j]&&ii<=L&&j<=L) ii++,j++,k++;
            else k=0;
            height[rank[i]]=k;
        }
    }
    inline void rmq() {
        for (long long i=1;i<=L;i++) t[i][0]=height[i];
        for (long long i=1,j=2;j<=L;j*=2,i++) {
            for (long long k=1;k<=L;k++) {
                if (k+j-1>L) break;
                t[k][i]=min(t[k][i-1],t[k+j/2][i-1]);
            }
        }
    }
    inline long long ask(long long l,long long r) {
        l=rank[l],r=rank[r];
        if (l>r) swap(l,r);
        l++; if (l>r) return 0;
        long long gt=g[r-l+1];
        return min(t[l][gt],t[r-b[gt]+1][gt]);
    }
}A,B;  
inline long long get(long long o) {
    long long s=-1;
    for (;o;o>>=1) s++;
    return s;
}
inline void Doit() {
    for (long long i=1;i<=N-5;i++) g[i]=get(i);
    for (long long i=0,s=1;s<=N-5;s*=2,i++) b[i]=s;
}
inline void work(long long l,long long r,long long p) {
    long long gt=B.ask(L-(l-1)+1,L-r+1),gtw=A.ask(r+1,l);
    l=l-gt,r=r+gtw;
	long long x=r-K*p+1;
	ans+=max(0ll,x-l+1);
}
int main() {
    Doit();
    scanf("%lld",&test);
    while (test--) {
		scanf("%lld",&K);
        scanf("%s",A.c+1); ans=0;
        L=strlen(A.c+1);
        if (K == 1) {
            printf("%lld\n", 1ll * L * (L + 1) / 2);
            continue;
        }
        for (i=1;i<=L;i++) B.c[L-i+1]=A.c[i];
        A.sa(),B.sa();
        A.geth(),B.geth();
        A.rmq(),B.rmq();
        for (j=1;j<=L/2;j++) {
            long long last=1;
            for (i=1+j;i<=L;i+=j) {
                if (A.ask(last,i)>=j) continue;
                work(last,i-1,j); 
                if (i+j-1<=L) last=i;
                else last=0;
            }
            if (last) work(last,L,j);
        }
        printf("%lld\n",ans);
    }
}
