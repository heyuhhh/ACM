#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
string s;
int l;
bool is(string ss){
    int f=1;
    for(int i=0;i<l;i++){
        int j=l-i-1;
        if(ss[i]!=ss[j]) f=0;
    }
    return f&&ss!=s;
}
int main(){
    cin>>s;
    l=s.length();
    int f=1;
    for(int i=1;i<l;i++){
        if(l&1 && i==l/2) continue ;
        if(s[i]!=s[0]) f=0;
    }
    if(f){
        puts("Impossible");
        return 0;
    }
    f=0;
    for(int i=1;i<l;i++){
        string t1=s.substr(0,i),t2=s.substr(i,l);
        t2+=t1;
        if(is(t2))f=1;
    }
    if(f) cout<<1<<endl;
    else cout<<2<<endl;
    return 0;
}
