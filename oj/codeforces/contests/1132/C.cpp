#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
int n,q;
struct P{
    int l,r;
    bool operator < (const P &A)const{
        return l<A.l;
    }
}p[N];
int sum[N],sum1[N],sum2[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=q;i++){
        cin>>p[i].l>>p[i].r;
        for(int j=p[i].l;j<=p[i].r;j++)sum[j]++;
    }
    int ans = 0;
    for(int i=1;i<=5000;i++){
        sum1[i]=sum1[i-1];sum2[i]=sum2[i-1];
        if(sum[i]==1) sum1[i]+=1;
        if(sum[i]==2) sum2[i]+=1;
        if(sum[i]) ans++;
    }
    sort(p+1,p+q+1);
    int sum = ans ;
    ans = 0;
    for(int i=1;i<=q;i++){
        for(int j=i+1;j<=q;j++){
            int l1=p[i].l,r1=p[i].r;
            int l2=p[j].l,r2=p[j].r;
            if(r1<l2){
                ans=max(ans,sum-(sum1[r1]-sum1[l1-1])-(sum1[r2]-sum1[l2-1]));
            }else{
                ans=max(ans,sum-(sum1[max(r1,r2)]-sum1[min(l1,l2)-1])-(sum2[min(r1,r2)]-sum2[max(l1,l2)-1]));
            }
        }
    }
    cout<<ans;
    return 0;
}
