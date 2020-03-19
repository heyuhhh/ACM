#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll n;
int q;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>q;
    while(q--){
        ll n,m,k;
        cin>>n>>m>>k;
        ll need = max(n,m);
        if(need>k){
            cout<< -1 << '\n';
            continue ;
        }
        ll tmp=k;
        k-=(need-1);
        if(n==m) cout<<min(n,m)-1+(k&1?k:k-2)<< '\n';
        else{
            ll now = max(n,m)-min(n,m);
            if(now%2==0){
                tmp-=need;
                cout<<min(n,m)+now+(tmp&1?tmp-2:tmp)<<'\n';
            }else{
                cout<<min(n,m)+now-1+k-1<<'\n';
            }
        }
    }
    return 0;
}
