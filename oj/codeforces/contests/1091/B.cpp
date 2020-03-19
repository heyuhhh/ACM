#include <bits/stdc++.h>
using namespace  std;
typedef long long ll;
const int N = 1005;
int n;
struct node{
    int x,y;
    bool operator < (const node &A)const{
        return A.x==x ? y<A.y : x<A.x;
    }
}p1[N],p2[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d%d",&p1[i].x,&p1[i].y);
    for(int i=1;i<=n;i++) scanf("%d%d",&p2[i].x,&p2[i].y);
    sort(p1+1,p1+n+1);sort(p2+1,p2+n+1);
    cout<<p1[1].x+p2[n].x<<" "<<p1[1].y+p2[n].y;
    return 0;
}
