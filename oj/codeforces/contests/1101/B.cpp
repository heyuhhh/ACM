#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 5e5+5;
char s[N];
int main(){
    scanf("%s",s);
    int len = strlen(s);
    int j=len,ans=0;
    for(int i=0;i<len;i++){
        if(j==len){
            if(s[i]=='[') ans++,j--;
            continue ;
        }else if(j==len-1){
            if(s[i]==':'){
                ans++;
                j=i;
                break ;
            }
        }
    }
    int k=0;
    for(int i=len-1;i>=0;i--){
        if(k==0){
            if(s[i]==']') ans++,k++;
            continue ;
        }else if(k==1){
            if(s[i]==':'){
                ans++;
                k=i;
                break ;
            }
        }
    }
    if(j>=k) puts("-1");
    else{
        for(int i=j+1;i<k;i++){
            if(s[i]=='|') ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
