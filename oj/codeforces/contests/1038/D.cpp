#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
const int N = 500005;
int n;
ll a[N];
priority_queue <pair<ll,int> > q;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        q.push(mp(a[i],i));
    }
    if(n==1){
        cout<<a[1];
        return 0;
    }
    int cnt = 0;
    ll ans = 0;
    while(!q.empty()){
        pair<ll,int> now=q.top();
        //cout<<now.first<<" "<<now.second<<endl;
        if(now.first>=0){ 
            cnt++;q.pop();
            if(q.empty()) ans-=now.first;
            else ans+=now.first;
        }else{
            if(cnt==0) ans+=now.first,q.pop();
            break ;
        }
    }
    while(!q.empty()){
        pair<ll,int> now=q.top();q.pop();
        ans-=now.first;
    }
    cout<<ans;
    return 0;
}
