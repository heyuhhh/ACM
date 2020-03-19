#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
char s[N];
int sum1[N],sum2[N];

int main(){
    int n;
    cin>>n;
    scanf("%s",s);
    int len = strlen(s),tot=0;
    s[len]='S';
    for(int i=0;i<=len;i++){
        if(s[i]=='G') tot++;
        else{
            sum1[i]=tot;
            tot=0;
        }
    }
    tot=0;
    for(int i=len;i>=0;i--){
        if(s[i]=='G') tot++;
        else{
            sum2[i]=tot;
            tot=0;
        }
    }
    int ans=0,cnt=0;
    for(int i=0;i<=len;i++){
        if(s[i]=='S') ans=max(ans,sum1[i]+sum2[i]);
        else cnt++;
    }
    if(ans!=cnt) ans++;
    cout<<ans;
    return 0;
}

