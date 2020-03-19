#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int a[N];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    cout<<min(a[n-1]-a[1],a[n]-a[2]);
    return 0;
}
