#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 205;
int l,k;
int vis[N];
string s;
vector <int> vec;
int main(){
    cin>>s;
    scanf("%d",&k);
    int len = s.length();
    int cnt1 = 0,cnt2 = 0;
    for(int i=0;i<len;i++){
        if(s[i]!='?'&&s[i]!='*') cnt1++;
        else cnt2++;
    }
    if(cnt1-cnt2>k){
        puts("Impossible");
        return 0;
    }
    if(cnt1>=k){
        int d=cnt1-k;
        while(d){
            for(int i=0;i<len;i++){
                if(s[i]=='*'||s[i]=='?'){
                    vis[i-1]=1;
                    d--;
                    if(d==0) break ;
                }
            }
        }
        for(int i=0;i<len;i++){
            if(vis[i]||s[i]=='*'||s[i]=='?') continue;
            cout<<s[i];
        }
    }else{
        int f=1;
        int d=k-cnt1;
        for(int i=0;i<len;i++){
            if(s[i]=='*'){
                s.insert(i,d,s[i-1]);
                f=0;
                break ;
            }
        }
        if(f){
            puts("Impossible");
            return 0;
        }
        len=s.length();
        for(int i=0;i<len;i++){
            if(vis[i]||s[i]=='*'||s[i]=='?') continue;
            cout<<s[i];
        }
    }
    return 0;
}
