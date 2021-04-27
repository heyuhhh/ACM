#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 100007;
int a[MAXN], b[MAXN];
bool vis[MAXN];
int xl[MAXN], xn;
typedef long long LL;
LL calc() {
    LL ans=0;
    for(unsigned k=0; k<(1u<<xn); k++) {
        LL now=0;
        for(int i=0; i<xn; i++) if(k&(1<<i)){
            now+=a[xl[i]];
            for(int j=(i+1)*2-1; j<xn; j+=(i+1)) if((k&(1<<(j)))) {
                now-=b[xl[j]];
            }
        }
        ans=max(ans, now);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for(int i=1; i<=n; i++) {
        cin >> b[i];
    }
    memset(vis,0,sizeof vis);
    LL ans=a[1];
    for(int i=2; 1ll*i*i<=n; i++) if(!vis[i]) {
        xn=0;
        vis[i]=1;
        xl[xn++]=i;
        for(long long j=i*i; j<=n; j*=i) {
            vis[j]=1;
            xl[xn++]=j;
        }
        ans += calc();
    }
    for(int i=2; i<=n; i++) if(!vis[i]) ans+=a[i];
    cout << ans << '\n';
}