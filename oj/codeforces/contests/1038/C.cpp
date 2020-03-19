#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
priority_queue <ll> q1,q2;
ll n;
ll a[N],b[N];
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>a[i],q1.push(a[i]);
    for(ll i=1;i<=n;i++) cin>>b[i],q2.push(b[i]);
    ll cur = 1;
    ll A = 0,B = 0;
    while(!q1.empty()||!q2.empty()){
        ll fir=0,sec=0;
        if(!q1.empty()) fir=q1.top();
        if(!q2.empty()) sec=q2.top();
        if(cur){
            if(fir>sec){
                A+=fir;
                q1.pop();
            }else{
                q2.pop();
            }
            cur^=1;
        }else{
            if(fir>sec){
                q1.pop();
            }else{
                B+=sec;
                q2.pop();
            }
            cur^=1;
        }
    }
    cout<<A-B;;
    return 0;
}
