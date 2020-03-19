#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,k;
int a[N];
set <int > S;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) S.insert(a[i]);
    int cnt=0;
    for(auto it=S.begin();it!=S.end();it++){
        cout<<*it-cnt<<endl;
        cnt+=*it-cnt;
        k--;
        if(k<=0) break;
    }
    while(k--) cout<<0<<endl;
    return 0;
}
