#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
int n,q;
int c[N],ans[N],pos[N];
int a[25];
struct P{
    int l,r,id;
    bool operator < (const P &A)const{
        return r<A.r;
    }
}p[N];
void insert(int val,int id){
    for(int i=20;i>=0;i--){
        if(!((1<<i)&val)) continue ;
        if(!a[i]){
            a[i]=val;
            pos[i]=id;
            break ;
        }
        if(pos[i]<id) swap(pos[i],id),swap(a[i],val);
        val^=a[i];
    }
}
int query(int l){
    int res=0;
    for(int i=20;i>=0;i--){
        if(((res^a[i])>res) && pos[i]>=l) res^=a[i];
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    cin>>q;
    for(int i=1;i<=q;i++) cin>>p[i].l>>p[i].r,p[i].id=i;
    sort(p+1,p+q+1);
    int r=1;
    for(int i=1;i<=q;i++){
        while(r<=p[i].r) insert(c[r],r),r++;
        ans[p[i].id]=query(p[i].l);
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
    return 0;
}
