#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
char s[N],p[N];
char a[N]={'R','B','G'};
void change(int x){
    for(int i=0;i<3;i++){
        p[x]=a[i];
        if(p[x]!=s[x-1] && p[x]!=s[x+1]) return ;
    }
    return ;
}
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    int ans = 0;
    int tot=0;
    for(int i=1;i<=n;i++) p[i]=s[i];
    for(int i=1;i<=n;i++){
        if(s[i]!=s[i-1]) tot=1;
        else{
            tot++;
            if(tot%2==0){
                change(i);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) cout<<p[i];
    return 0;
}
