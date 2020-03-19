#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
char s[N],a[N];
char p[10]={'R','B','G'};
int main(){
    scanf("%d",&n);
    scanf("%s",s);
    int ans = 0;
    sort(p,p+3);
    ans=0x3f3f3f3f3f;
    int tot=0;
    do{
            tot++;
       int cnt = 0;
       for(int i=0;i<min(n,3);i++){
            if(p[i]!=s[i]) cnt++;
       }
       for(int i=3;i<n;i++){
            if(p[i%3]!=s[i]) cnt++;
       }
       if(ans>cnt){
        ans=cnt;
        for(int i=0;i<3;i++) a[i]=p[i];
       }
    }while(next_permutation(p,p+3));
    cout<<ans<<endl;
    for(int i=0;i<n;i++) cout<<a[i%3];
    return 0;
}
