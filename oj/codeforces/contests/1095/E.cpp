#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int n;
char s[N];
int l[N],r[N],dl[N],dr[N];
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    int d=0;
    l[0]=1;r[n+1]=1;
    for(int i=1;i<=n;i++){
        if(s[i]=='(') d++;
        else d--;
        if(d<0) l[i]=0;
        else l[i]=l[i-1];
        dl[i]=d;
    }
    d=0;
    for(int i=n;i>=1;i--){
        if(s[i]==')') d++;
        else d--;
        if(d<0) r[i]=0;
        else r[i]=r[i+1];
        dr[i]=d;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(l[i-1]&&r[i+1]){
            int now = dl[i-1]-dr[i+1];
            if(s[i]=='(' && now==1) ans++;
            else if(s[i]==')' && now==-1) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
