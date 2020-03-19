#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,k;
int a[N];
char s[N];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%s",s+1);
    priority_queue <int> q;
    q.push(a[1]);
    ll ans = 0;
    for(int i=2;i<=n;i++){
        if(s[i]==s[i-1]) q.push(a[i]);
        else{
            int cnt = 0;
            while(!q.empty()){
                int now = q.top();q.pop();
                cnt++;
                if(cnt<=k) ans+=now;
            }
            q.push(a[i]);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int now = q.top();q.pop();
        cnt++;
        if(cnt<=k) ans+=now;
    }
    cout<<ans;
    return 0;
}
