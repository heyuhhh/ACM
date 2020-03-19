#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 305,M = 305;
int a[N],mx[N],mn[N],b[N];
struct seg{
    int l,r,id;
    bool operator < (const seg &A)const{
        return r<A.r;
    }
}p[M];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
    for(int i=1;i<=m;i++) scanf("%d%d",&p[i].l,&p[i].r),p[i].id=i;
    sort(p+1,p+m+1);
    memset(mn,INF,sizeof(mn));
    for(int i=1;i<=n+1;i++) mx[i]=-INF;
    for(int i=n;i>=1;i--)
        mx[i]=max(mx[i+1],a[i]);
    for(int i=n;i>=1;i--)
        mn[i]=min(mn[i+1],a[i]);
    int ans = mx[1]-mn[1];
    int num=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) a[j]=b[j];
        for(int j=1;j<=m;j++){
            if(p[j].l<=i && p[j].r>=i){
                for(int k=p[j].l;k<=p[j].r;k++) a[k]--;
            }
        }
        int minx = INF,maxx = -INF;
        for(int j=1;j<=n;j++) minx=min(minx,a[j]),maxx=max(maxx,a[j]);
        if(ans<maxx-minx){
            ans=maxx-minx;
            num=i;
        }
    }
    cout<<ans<<endl;
    int tot=0;
    vector <int> vec;
    for(int i=1;i<=m;i++){
        if(p[i].l<=num && p[i].r>=num) tot++,vec.push_back(p[i].id);
    }
    cout<<tot<<endl;
    for(auto v:vec) cout<<v<<" ";
    return 0;
}
