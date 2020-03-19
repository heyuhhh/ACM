#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,m,x;
struct Point{
    ll x,y;
    bool operator < (const Point &A)const{
        return  x<A.x;
    }
}p[N];
int check(long double mid){
    m=0;
    long double l=-1e17,r=1e17;
    for(int i=1;i<=n;i++){
        long double ll=fabs(p[i].y-mid);
        if(mid*mid<ll*ll) return 0;
        long double dx = sqrt(mid*mid-ll*ll);
        l=max(p[i].x-dx,l);
        r=min(p[i].x+dx,r);
    }
    return l<=r;
}
int main(){
    scanf("%d",&n);
    int f=0;
    for(int i=1;i<=n;i++){
        scanf("%I64d%I64d",&p[i].x,&p[i].y);
        if(p[i].y*p[1].y<0) f=1;
    }
    sort(p+1,p+n+1);
    if(f){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++) p[i].y=fabs(p[i].y);
    long double l=0,r=1e16,mid;
    for(int i=1;i<=200;i++){
        mid=(l+r)/2.0;
        if(check(mid)) r=mid;
        else l=mid;
    }
    if(fabs(l-1e16)<1) cout<<-1;
    else printf("%.15f",(double)l);
    return 0;
}
