#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int a[N][5];
int n;
int vis[N];
vector <int> ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i][0],&a[i][1]);
    ans.push_back(1);
    vis[1]=1;
    for(int i=1;i<=n;i++){
        int p1=a[i][0],p2=a[i][1];
        if(vis[p1]&&vis[p2])break ;
        vis[p1]=vis[p2]=1;
        if(a[p1][0]==p2 || a[p1][1]==p2){
            ans.push_back(p1);
            ans.push_back(p2);
            i=p2-1;
        }else{
            ans.push_back(p2);
            ans.push_back(p1);
            i=p1-1;
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}
