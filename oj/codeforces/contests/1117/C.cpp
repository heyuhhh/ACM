#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
struct Point{
    ll x,y;
}st,ed,cur;
char s[N];
int n;
ll prex[N],prey[N];
int check(ll x){
    ll d = x/n;
    cur.x=st.x+d*prex[n];
    cur.y=st.y+d*prey[n];
    cur.x=cur.x+prex[x%n];
    cur.y=cur.y+prey[x%n];
    ll dis=abs(cur.x-ed.x)+abs(cur.y-ed.y);
    return dis<=x;
}
int main(){
    cin>>st.x>>st.y>>ed.x>>ed.y;
    cin>>n;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        prex[i]=prex[i-1];prey[i]=prey[i-1];
        prex[i]+=(s[i]=='R');
        prex[i]-=(s[i]=='L');
        prey[i]+=(s[i]=='U');
        prey[i]-=(s[i]=='D');
    }
    ll l=0,r=1e15,mid;
    while(l<r){
        mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(l==1e15) cout<<-1;
    else cout<<l;
    return 0;
}
