#include <bits/stdc++.h>
using namespace std;
int t;
const int N = 1005;
char s[N];
int main(){
    cin>>t;
    while(t--){
        scanf("%s",s);
        int flag = 1;
        int len  =strlen(s);
        s[len]=s[0];
        for(int i=1;i<=len;i++){
            if(s[i]!=s[0]) flag=0;
        }
        if(flag) cout<<-1<<endl;
        else{
            sort(s,s+len);
            for(int i=0;i<len;i++) cout<<s[i];
            cout<<endl;
        }
    }
    return 0;
}
