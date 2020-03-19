#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
char mp[N][N];
int n;
int pd(int x,int y){
    if(mp[x-1][y-1]=='X' && mp[x-1][y+1]=='X' && mp[x+1][y+1]=='X' && mp[x+1][y-1]=='X') return 1;
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%s",mp[i]+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]=='X' && pd(i,j)) ans++;
        }
    }
    cout<<ans;
    return 0;
}
