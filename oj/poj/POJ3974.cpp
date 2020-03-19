#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int N = 2000005;
char s[N],tmp[N];;
int p[N];
void Manacher(char *s){
    memset(p,0,sizeof(p));
    int l=strlen(s);
    strcpy(tmp,s);
    s[0]='$';
    for(int i=1;i<=2*l+1;i++){
        if(i&1) s[i]='#';
        else s[i]=tmp[i/2-1];
    }
    s[2*l+2]='\0';
    int mx=0,id=0;
    l=strlen(s);
    for(int i=1;i<l;i++){
        if(i>=mx) p[i]=1;
        else p[i]=min(mx-i,p[2*id-i]);
        while(s[i-p[i]]==s[i+p[i]]) p[i]++;
        if(p[i]+i>mx){
            mx=p[i]+i;
            id=i;
        }
    }
}
int main(){
    int cnt = 0;
    while(scanf("%s",s)!=EOF){
        cnt++;
        if(s[0]=='E'&&s[1]=='N') break;
        Manacher(s);
        int ans = 0;
        int l=strlen(s);
        for(int i=1;i<l;i++) ans=max(ans,p[i]-1);
        printf("Case %d: ",cnt);
        printf("%d\n",ans);
    }
    return 0;
}
