#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int n;
struct node{
    ll id;
    ll v;
    bool operator < (const node &A)const{
        return v>A.v;
    }
}a[N];
ll ans;
ll p[65];
void xor_base(){
    ans=0;
    for(int i=1;i<=n;i++){
        int flag=0;
        for(ll j=62;j>=0;j--){
            if((1LL<<j)&a[i].id){
                if(!p[j]){
                    p[j]=a[i].id;
                    flag=1;
                    break;
                }
                a[i].id^=p[j];
            }
        }
        if(flag) ans+=a[i].v;
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].id>>a[i].v;
    }
    sort(a+1,a+n+1);
    xor_base();
    cout<<ans;
    return 0;
}
