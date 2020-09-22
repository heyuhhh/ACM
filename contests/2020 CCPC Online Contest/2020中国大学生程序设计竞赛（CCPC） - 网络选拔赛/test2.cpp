#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,md;
const int N=1000500;
ll Sqr,w[N];
ll pri[N],id1[N],id2[N],g[N],m;
bool zs[N];
int tot,spg[N];
ll qp(ll a,ll b,ll mod=md){
    ll ret=1;
    for(;b;b>>=1){
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
    }
    return ret;
}
void pre(int sz){
    zs[1]=true;
    for(int i=2;i<=sz;++i){
        if(!zs[i]){
            pri[++tot]=i;
            spg[tot]=(spg[tot-1]+i)%md;
        }
        for(int j=1;j<=tot && pri[j]*i<=sz;j++){
            zs[pri[j]*i]=true;
            if(i%pri[j]==0) break;
        }
    }
}
ll gao(ll x){
    x%=md;
    return x*(x-1+md)%md;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        tot=0,m=0;
        ll tmp;
        scanf("%lld%lld",&tmp,&md);
        if(tmp==1){
            printf("0\n");
            continue;
        }
        else if(tmp==2){
            printf("6\n");
            continue;
        }
        n=tmp+1;
        Sqr=sqrt(n);
        pre(Sqr);
        for(ll i=1,j;i<=n;i=j+1){
            j=n/(n/i);w[++m]=n/i;
            ll x=w[m]%md;
            g[m]=(1+x)*x%md*((md+1)/2)%md;
            g[m]=(g[m]-1+md)%md;
            if(w[m]<=Sqr) id1[w[m]]=m;
            else id2[j]=m;
        }
        for(int j=1;j<=tot;++j){
            for(int i=1;i<=m && pri[j]*pri[j]<=w[i];++i){
                int k=(w[i]/pri[j]<=Sqr)?id1[w[i]/pri[j]]:id2[n/(w[i]/pri[j])];
                (g[i]-=1ll*pri[j]%md*(g[k]-spg[j-1]+md)%md)%=md;
                if(g[i]<0) g[i]+=md;
            }
        }
        int k=(n<=Sqr)?id1[n]:id2[1];
        ll ans=(g[k]-spg[k-1]+md)%md;
        //printf("%lld\n",ans);
        ans-=2;
        ans=(ans+md)%md;
        //printf("%lld\n",ans);
        ll su=(3+n)%md*((n-2)%md)%md*((md+1)/2)%md;
       // printf("%lld\n",su);
        printf("%lld\n",(ans+su)%md);
    }
}