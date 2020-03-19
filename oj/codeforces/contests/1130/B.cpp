#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
struct Node{
    int val,id;
    bool operator < (const Node &A)const{
        return val<A.val;
    }
}a[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=2*n;i++){
        cin>>a[i].val;
        a[i].id=i;
    }
    sort(a+1,a+2*n+1);
    ll ans = 0;
    ans+=a[1].id+a[2].id-2;
    for(int i=3;i<=2*n;i+=2){
        ans+=min(abs(a[i].id-a[i-1].id)+abs(a[i+1].id-a[i-2].id),abs(a[i].id-a[i-2].id)+abs(a[i+1].id-a[i-1].id));
    }
    cout<<ans;
    return 0;
}
