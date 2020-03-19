#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
int w,h;
int u[5],d[5];
int main(){
    cin>>w>>h>>u[1]>>d[1]>>u[2]>>d[2];
    int ans = w;
    for(int i=h;i>=1;i--){
        ans+=i;
        if(d[1]==i) ans=max(0,ans-u[1]);
        if(d[2]==i) ans=max(0,ans-u[2]);
    }
    cout<<ans;
    return 0;
}
