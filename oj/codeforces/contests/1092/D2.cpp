#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =2e5+5;
int n;
int a[N];
int main(){
    scanf("%d",&n);
    int mx=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
    stack <int> S;
    int pre = -1;
    for(int i=1;i<=n;i++){
        int now ;
        if(!S.empty()) now = S.top();
        else{
            S.push(a[i]);
            pre = -1;
            continue ;
        }
        if(now == a[i] && now>=pre){
            S.pop();
            pre = now;
        }else S.push(a[i]),pre=-1;
    }
    int cnt = 0,now = mx;
    while(!S.empty()){
        cnt++;
        now = S.top();
        S.pop();
    }
    if(cnt>1 || now!=mx){
        cout<<"NO";
    }else cout<<"YES";
    return 0;
}

