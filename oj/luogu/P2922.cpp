#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
int n,m,cnt,tot;
int s[N],val[N];
struct Trie{
    int node,son,left,sum;
}tre[N];
void init(){
    tre[0].son=tre[0].left=-1;tot=1;
}
void insert(){
    int j,u=0;
    for(int i=0;i<cnt;i++){
        bool flag=false;
        for(j=tre[u].son;j!=-1;j=tre[j].left){
            if(tre[j].node==s[i]){
                flag=true;
                break ;
            }
        }
        if(!flag){
            j=tot++;
            tre[j].left=tre[u].son;
            tre[u].son=j;
            tre[j].node=s[i];
            tre[j].son=-1;
        }
        tre[j].sum++;
        u=j;
    }
    val[u]++;
}
int query(){
    int ans = 0;
    int u=0,j;
    for(int i=0;i<cnt;i++){
        bool flag=false;
        for(j=tre[u].son;j!=-1;j=tre[j].left){
            if(tre[j].node==s[i]){
                flag=true;
                break ;
            }
        }
        if(!flag) break ;
        if(i==cnt-1){
            ans+=tre[j].sum;
            break ;
        }
        ans+=val[j];
        u=j;
    }
    return ans ;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>m>>n;
    init();
    for(int i=1;i<=m;i++){
        int k,p;cnt=0;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>p;
            s[cnt++]=p;
        }
        insert();
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans=cnt=0;int k,p;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>p;
            s[cnt++]=p;
        }
        ans+=query();
        cout<<ans<<'\n';
    }
    return 0;
}

