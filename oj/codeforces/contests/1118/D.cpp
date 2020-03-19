#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
int n,m;
int a[N];
int check(int x){
    int i;
    ll sum=0,cnt=0;
    for(i=1;i<=n;i++){
        sum+=a[i]-cnt;
        if(i%x==0) cnt++;
        if(sum>=m) return true;
    }
    return false;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    int l=1,r=1e9+1,mid;
    while(l<r){
        mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(l==1e9+1) cout<<-1;
    else cout<<l;
    return 0;
}
