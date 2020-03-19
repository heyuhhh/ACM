#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x,y,z;
int a,b,c;

int main(){
    cin>>x>>y>>z>>a>>b>>c;
    if(a>=x && a-x+b>=y && a+b+c-x-y>=z) cout<<"YES";
    else cout<<"NO";
    return 0;
}
