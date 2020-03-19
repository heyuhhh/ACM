#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int n,x,y;
int a[N];
int main(){
    scanf("%d%d%d",&n,&x,&y);
    int cnt= 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]<=x) cnt++;
    }
    if(x>y) cout<<n;
    else{
        cout<<(cnt+1)/2;
    }
    return 0;
}
