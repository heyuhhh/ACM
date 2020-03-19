#include <bits/stdc++.h>
using namespace std;

typedef long long ll ;
int t;

ll w(ll a,ll b){
    return ((b+1)/2)*((a+1)/2)+(b/2)*(a/2);
}
ll sub_w(ll x1,ll y1,ll x2,ll y2){
    return w(x2,y2)-w(x1-1,y2)-w(x2,y1-1)+w(x1-1,y1-1);
}
ll sub_b(ll x1,ll y1,ll x2,ll y2){
    return (x2-x1+1)*(y2-y1+1)-sub_w(x1,y1,x2,y2);
}
int main(){
    scanf("%d",&t);
    while(t--){
        ll n,m,x1,x2,x3,x4,y1,y2,y3,y4;
        cin>>n>>m>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        ll sub_x1 = max(x1,x3),sub_y1=max(y1,y3),sub_x2=min(x2,x4),sub_y2=min(y2,y4);
        ll num_w = w(n,m),num_b = n*m - num_w;
        num_w+=sub_b(x1,y1,x2,y2);num_b-=sub_b(x1,y1,x2,y2);
        num_b+=sub_w(x3,y3,x4,y4);num_w-=sub_w(x3,y3,x4,y4);
        if(sub_x1<=sub_x2 && sub_y1<=sub_y2){
            num_b+=sub_b(sub_x1,sub_y1,sub_x2,sub_y2);
            num_w-=sub_b(sub_x1,sub_y1,sub_x2,sub_y2);
        }
        cout<<num_w<<" "<<num_b<<endl;
    }
    return 0;
}

