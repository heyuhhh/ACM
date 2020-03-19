#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 55;
int T,n;
int a[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    int Case = 0;
    while(T--){
        Case++ ;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int cnt = 0;
        for(int i=1;i<=n;i++){
            for(int j=30;j>=0;j--) if(a[i]&(1<<j)) cnt++;
        }
        cout<<"Case "<<Case<<": ";
        if((cnt+n)&1) cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
    return 0;
}
