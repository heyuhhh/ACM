#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int Map[N][N],vis[N],a[N];
int n;

int main(){
    scanf("%d",&n);
    int cnt = 0,tot = 0,st = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1) cnt++;
        else st=i;
    }
    vis[st]=1;bool flag=false;
    int end=st;
    for(int i=st;;i=end){
        if(flag) break;
        int tmp=0;
        for(int j=1;j<=n;j++){
            if(a[j]>1 && !vis[j]){
                tmp++;
                Map[i][j]=Map[j][i]=1;
                vis[j]=1;
                a[i]--;a[j]--;
                end=j;
                break;
            }
        }
        if(!tmp) flag=true;
    }
    int tmp = 0;
    for(int i=1;i<=n;i++) if(vis[i]) tot+=a[i],tmp++;
    if(cnt>tot){
        cout<<"NO";
        return 0;
    }
    int ans,edges=tmp-1;
    if(cnt>1) ans=edges+2;
    else if(cnt==1) ans=edges+1;
    else ans=edges;
    cout<<"YES"<<" "<<ans<<endl;
    if(cnt){
        cnt--;
        for(int i=1;i<=n;i++) if(!vis[i]){
            vis[i]=Map[i][st]=Map[st][i]=1;
            edges++;
            a[st]--;a[i]--;
            break ;
        }
        if(cnt){
            cnt--;
            for(int i=1;i<=n;i++) if(!vis[i]){
                vis[i]=Map[i][end]=Map[end][i]=1;
                edges++;
                a[end]--;a[i]--;
                break;
            }
        }
        if(cnt){
            for(int i=n;i>=1;i--) if(!vis[i]){
                vis[i]=1;
                for(int j=1;j<=n;j++){
                    if(a[j] && vis[j] &&j!=i){
                        edges++;
                        Map[j][i]=Map[i][j]=1;
                        a[j]--;a[i]--;
                        break;
                    }
                }
            }
        }
    }
    cout<<edges<<endl;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(Map[i][j]) printf("%d %d\n",i,j);
    return 0;
}

