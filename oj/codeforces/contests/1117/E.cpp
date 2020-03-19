#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
char str[N],s[N],ans[N];
ll f[N];
int main(){
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<3;i++){
        for(int j=0;j<len;j++){
            if(i==0) s[j]='a'+j%26;
            if(i==1) s[j]='a'+j/26%26;
            if(i==2) s[j]='a'+j/26/26%26;
        }
        printf("? %s\n",s);
        fflush(stdout);
        char tmp[N];
        scanf("%s",tmp);
        for(int j=0;j<len;j++){
            if(i==0) f[j]+=tmp[j]-'a';
            if(i==1) f[j]+=(tmp[j]-'a')*26;
            if(i==2) f[j]+=(tmp[j]-'a')*26*26;
        }
    }
    char ans[N];
    for(int i=0;i<len;i++){
        ans[f[i]]=str[i];
    }
    printf("! ");
    printf("%s",ans);
    return 0;
}
