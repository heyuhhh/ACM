#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
ll l,r,d;

int main(){
    cin>>q;
    while(q--){
        cin>>l>>r>>d;
        if(d<l || d>r) cout<<d<<endl;
        else{
            ll now = r/d;
            cout<<(now+1)*d<<endl;
        }
    }
    return 0;
}
