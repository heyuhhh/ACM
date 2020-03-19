#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 1e5+5,M = 305;
int n,m;
int a[N],b[N],l[N],r[N];
vector <int> pl[N],pr[N];
int main(){
    cin>>n>>m;
    int mx = -INF ,mn= INF;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&l[i],&r[i]);
        pl[l[i]].push_back(i);
        pr[r[i]+1].push_back(i);
    }
    int ans = mx-mn,pos=-1,tmp;
    for(int i=1;i<=n;i++){
        int len1=pl[i].size(),len2=pr[i].size();
        if(len1){
            for(auto v:pl[i]){
                for(int j=l[v];j<=r[v];j++) a[j]--;
            }
        }
        if(len2){
            for(auto v:pr[i]){
                for(int j=l[v];j<=r[v];j++) a[j]++;
            }
        }
        if(len1 || len2){
            mx = -INF,mn = INF;
            for(int i=1;i<=n;i++){
                mx=max(mx,a[i]);
                if(a[i]<mn){
                    mn=a[i];
                    tmp=i;
                }
                if(mx-mn>ans){
                    ans=mx-mn;
                    pos=tmp;
                }
            }
        }
    }
    cout<<ans<<endl;
    int cnt = 0;
    for(int i=1;i<=m;i++){
        if(l[i]<=pos && r[i]>=pos) cnt++;
    }
    cout<<cnt<<endl;
    for(int i=1;i<=m;i++){
        if(l[i]<=pos && r[i]>=pos) cout<<i<<" ";
    }
    return 0;
}
