#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll w1,h1,w2,h2;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>w1>>h1>>w2>>h2;
    ll ans = 0;
    ans+=(h1+h2+2)*(max(w1,w2)+2);
    ll now=min(w1,w2);
    ll tmp=max(w1,w2)-now;
    if(w1<w2) ans-=h1*tmp;
    else ans-=h2*tmp;
    ans-=(w1*h1+w2*h2);
    cout<<ans;
    return 0;
}
