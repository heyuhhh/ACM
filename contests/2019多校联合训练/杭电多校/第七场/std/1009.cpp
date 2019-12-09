#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
const ll mod=1e9+7;
inline int flg(ll n){
    return (n>0)-(n<0);
}
void exgcd(ll a,ll b,ll &x,ll &y){
if (!b){
x=a; y=0; return;
}
exgcd(b,a%b,y,x);
y-=a/b*x;
}
ll inv(ll n){
ll x,y;
exgcd(n,mod,x,y);
return x;
}
struct vect{
    ll l,r,k;
    bool bel,par;
    vect(){};
    vect(ll x1,ll y1,ll x2,ll y2,bool _b){
        bel=_b;
        if (y1==y2){
            par=true; k=x2-x1;
            l=r=y1;
            return;
        }
        par=false;
        k=(x2-x1)*inv(y2-y1)%mod*flg(y2-y1);
        l=min(y1,y2);
        r=max(y1,y2);
    }
};
struct cmp1{
    inline bool operator () (const vect &a,const vect &b) const{
        return a.l>b.l;
    }
};
struct cmp2{
    inline bool operator () (const vect &a,const vect &b) const{
        return a.r>b.r;
    }
};
priority_queue<vect,vector<vect>,cmp1> que1;
priority_queue<vect,vector<vect>,cmp2> que2;
int inv2=inv(2),inv3=inv(3);
ll cal(ll a1,ll b1,ll a2,ll b2,ll x){
    ll ans=0;
    ans+=a1*a2%mod*x%mod*x%mod*x%mod*inv3%mod;
    ans+=(a1*b2+a2*b1)%mod*x%mod*x%mod*inv2%mod;
    ans+=b1*b2%mod*x%mod;
    return ans%mod;
}
ll det(ll x1,ll y1,ll x2,ll y2){
return x1*y2-x2*y1;
}
int main(){
    int tt;
    int i,n,m;
    bool cnt1,cnt2;
    ll x0,y0,x1,y1,x2,y2;
    ll val1,val2,k1,k2,mx,ans;
    ll l,r;
    ll s1,s2;
    vect vt;
    scanf("%d",&tt);
    while (tt--){
        scanf("%d",&n);
        mx=-1e18; s1=0; s2=0;
        scanf("%lld%lld",&x0,&y0);
        x1=x0; y1=y0; mx=max(mx,y0);
        for (i=1;i<n;i++){
            scanf("%lld%lld",&x2,&y2);
            que1.push(vect(x1,y1,x2,y2,0));
            s1+=det(x1-x0,y1-y0,x2-x0,y2-y0);
            x1=x2; y1=y2; mx=max(mx,y2);
        }
        scanf("%d",&m);
        que1.push(vect(x1,y1,x0,y0,0));
        scanf("%lld%lld",&y0,&x0);
        x1=x0; y1=y0; mx=max(mx,y0);
        for (i=1;i<m;i++){
            scanf("%lld%lld",&y2,&x2);
            que1.push(vect(x1,y1,x2,y2,1));
            s2+=det(x1-x0,y1-y0,x2-x0,y2-y0);
            x1=x2; y1=y2; mx=max(mx,y2);
        }
        que1.push(vect(x1,y1,x0,y0,1));
        cnt1=false;
        cnt2=false;
        val1=val2=k1=k2=0;
        r=que1.top().l;
        ans=0;
        while (!que1.empty()||!que2.empty()){
            l=r;
            while (!que1.empty()&&que1.top().l<=l){
                vt=que1.top(); que1.pop();
                if (vt.bel){
                    if (vt.par) val1=(val1+vt.k)%mod;
                    else{
                        k1=(k1+vt.k)%mod;
                        que2.push(vt);
                    }
                }
                else{
                    if (vt.par) val2=(val2+vt.k)%mod;
                    else{
                        k2=(k2+vt.k)%mod;
                        que2.push(vt);
                    }
                }
            }
            while (!que2.empty()&&que2.top().r<=l){
                vt=que2.top(); que2.pop();
                if (vt.bel)
                    k1=(k1-vt.k)%mod;
                else k2=(k2-vt.k)%mod;
            }
            r=mx;
            if (!que1.empty()) r=min(r,que1.top().l);
            if (!que2.empty()) r=min(r,que2.top().r);
            ans+=cal(k1,val1,k2,val2,r-l);
            val1=(val1+k1*(r-l))%mod;
            val2=(val2+k2*(r-l))%mod;
        }
        printf("%I64d\n",(ans*flg(s1)*flg(s2)%mod+mod)%mod);
    }
    return 0;
}