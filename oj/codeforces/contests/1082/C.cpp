#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,m;
vector <int> vec[N];
int main(){
    scanf("%d%d",&n,&m);
    int maxn = 0;
    int ans=0;
    for(int i=1;i<=n;i++){
        int s,r;
        scanf("%d%d",&s,&r);
        vec[s].push_back(r);
        int tmp=vec[s].size();
        maxn=max(maxn,tmp);
    }
    for(int i=1;i<=m;i++){
        sort(vec[i].begin(),vec[i].end());
        reverse(vec[i].begin(),vec[i].end());
    }
    int sum[N]={0};
    for(int i=1;i<=m;i++){
        int tot=0;
        int len=vec[i].size();
        for(int j=0;j<len;j++){
            tot+=vec[i][j];
            if(tot>0) sum[j+1]+=tot;
            else tot=0;
        }
    }
    for(int i=1;i<=maxn;i++) ans=max(ans,sum[i]);
    cout<<ans;
    return 0;
}

