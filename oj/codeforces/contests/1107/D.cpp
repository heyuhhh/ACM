#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5205;
int n;
char s[N][N];
vector <int> vec;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=1;i<=n;i++){
        int flag=1;
        if(n%i!=0) continue ;
        for(int j=0;j<n;j++){
            if(strcmp(s[(j/i)*i],s[j])!=0){
                flag=0;
                break ;
            }
        }
        if(flag) vec.push_back(i);
    }
    reverse(vec.begin(),vec.end());
    int flag;
    for(auto v:vec){
        flag=1;
        for(int i=0;i<n;i+=v){
            vector <int> a;
            for(int j=0;j<n/4;j++){
                char c = s[i][j];
                int now;
                if(c>='A' && c<='F') now=c-'A'+10;
                else now=c-'0';
                for(int k=3;k>=0;k--){
                    if((1<<k)&now) a.push_back(1);
                    else a.push_back(0);
                }
            }
            for(int k=0;k<n;k++){
                if(a[(k/v)*v]-'0'!=a[k]-'0'){
                    flag=0;
                    break ;
                }
            }
            if(!flag)  break ;
        }
        if(flag){
            cout<<v;
            return 0;
        }
    }
    return 0;
}
