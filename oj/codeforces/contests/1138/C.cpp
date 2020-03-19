#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int n,m;
int mp[N][N];
int r[N][N],c[N][N];
int mx1[N],mx2[N];
struct node{
    int v,id;
    bool operator <(const node&A){
        return v<A.v;
    }
}a[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            r[i][j]=c[i][j]=mp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            a[j].v=mp[i][j];a[j].id=j;
        }
        sort(a+1,a+m+1);
        int cnt = 0;
        for(int j=1;j<=m;j++){
            if(a[j].v==a[j-1].v) cnt++;
            r[i][a[j].id]=j-cnt;
            mx1[i]=max(mx1[i],j-cnt);
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<r[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            a[i].v=mp[i][j];a[i].id=i;
        }
        sort(a+1,a+n+1);
        int cnt = 0;
        for(int i=1;i<=n;i++){
            if(a[i].v==a[i-1].v) cnt++;
            c[a[i].id][j]=i-cnt;
            mx2[j]=max(mx2[j],i-cnt);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int mx=max(mx1[i],mx2[j]);
            int tmp1=r[i][j],tmp2=c[i][j];
            int ans = 0;
            if(tmp1>tmp2){
                ans=max(mx1[i],mx2[j]+tmp1-tmp2);
            }else if(tmp1<tmp2){
                ans=max(mx2[j],mx1[i]+tmp2-tmp1);
            }else{
                ans=max(mx1[i],mx2[j]);
            }
            //ans=max(mx1[i],mx2[j])+abs(tmp1-tmp2);
            cout<<ans<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
