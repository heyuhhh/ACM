#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
const ll N = 5e5+5;
ll n;
char s[N],t[N];
int f[N];
void Getfail(char *P){
    memset(f,0,sizeof(f));
    int l=strlen(P);
    for(int i=1;i<l;i++){
        int j=f[i];
        while(j && P[i]!=P[j]) j=f[j];
        f[i+1]=P[j]==P[i] ? j+1 : 0;
    }
}
int main(){
    scanf("%s",s);
    scanf("%s",t);
    Getfail(t);
    ll l1=strlen(s),l2=strlen(t);
    ll c1=0,c2=0;
    ll tmp=l2-f[l2];
    t[tmp]='\0';
    l2=strlen(t);
    for(ll i=0;i<l1;i++){
        if(s[i]=='1')c1++;
    }
    for(ll i=0;i<l2;i++){
        if(t[i]=='1')c2++;
    }
    ll d1=l1-c1,d2=l2-c2;
    if(c2==0 || d2==0){
        for(ll i=1;i<=d1;i++) cout<<'0';
        for(ll i=1;i<=c1;i++) cout<<'1';
        return 0;
    }
    ll l=0;

    while(c1-c2>=0 && d1-d2>=0){
        if(l+l2>l1) break ;
        printf("%s",t);
        c1-=c2;d1-=d2;l+=l2;
    }
    for(int i=0;;i++){
        if(i>=l2) i-=l2;
        if(t[i]=='1'&&c1){
            c1--;
            cout<<1;
        }
        else if(t[i]=='0' && d1){
            d1--;
            cout<<0;
        }
        if(c1==0&&d1==0) break ;
    }
    return 0;
}
