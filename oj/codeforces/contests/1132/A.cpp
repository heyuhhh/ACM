#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt1,cnt2,cnt3,cnt4;

int main(){
    cin>>cnt1>>cnt2>>cnt3>>cnt4;
    if(cnt1!=cnt4) cout<<0;
    else if(cnt1==0 && cnt3>0) cout<<0;
    else cout<<1;
    return 0;
}
