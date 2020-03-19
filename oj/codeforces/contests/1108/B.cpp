#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200;
int n;
int d[N],del[N];
vector <int> vec[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    sort(d+1,d+n+1);
    for(int i=1;i<=n;i++){
        int x=d[i];
        for(int j=2;j*j<=x;j++){
            if(x%j==0){
                vec[i].push_back(j);
                if(j*j!=x) vec[i].push_back(x/j);
            }
        }
    }
    for(int i=n;i>=1;i--){
        if(del[i]) continue ;
        int cnt = 0;
        while(cnt<vec[i].size()){
            for(int j=2;j<=i;j++){
                if(del[j]) continue ;
                if(d[j]==vec[i][cnt]){
                    cnt++;
                    del[j]=1;
                    if(cnt==(int)vec[i].size()) break ;
                }
            }
        }
    }
    int tot=0;
    for(int i=3;i<=n;i++) if(!del[i]) tot++;
    int now = 0;
    int x=1,y=1;
    for(int i=3;i<=n;i++){
        if(now==tot-1){
            if(!del[i]) y*=d[i];
        }
        else if(!del[i]) x*=d[i],now++;
    }
    cout<<x<<" "<<y;
    return 0;
}
