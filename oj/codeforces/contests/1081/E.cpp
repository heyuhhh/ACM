#include <bits/stdc++.h>
#define mx 2e5
using namespace std;
typedef long long ll;
const int N =2e5+5;
ll a[N];
int n;
vector <int> Div[N];
int main(){
    cin>>n;
    for(int i=2;i<=n;i+=2) scanf("%I64d",&a[i]);
    for(int i=1;i<=mx;i++)
        for(int j=i;j<=mx;j+=i) Div[j].push_back(i); //nlognÔ¤´¦Àí
    ll last = 0;
    for(int i=2;i<=n;i+=2){
        ll mn=2e18;
        for(auto v:Div[a[i]]){
            int d=a[i]/v;
            if(d%2==v%2){
                ll now = (max(d,v)-min(d,v))/2;
                if(now*now>last)
                mn = min(mn,now*now);
            }
        }
        if(mn==2e18){
            puts("No");return 0;
        }
        a[i-1]=mn-last;
        last = a[i]+mn;
    }
    puts("Yes");
    for(int i=1;i<=n;i++){
        printf("%I64d ",a[i]);
    }
    return 0;
}

