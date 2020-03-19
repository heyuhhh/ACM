#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n;
int a[N];
char s[N];
int main(){
    scanf("%s",s);
    int l=strlen(s);
    int h1=0,m1=0,h2=0,m2=0;
    int f=1;
    for(int i=0;i<l;i++){
        if(s[i]==':'){
            f=0;continue;
        }
        if(f){
            h1=h1*10+s[i]-'0';
        }else{
            m1=m1*10+s[i]-'0';
        }
    }
    scanf("%s",s);
    l=strlen(s);
    f=1;
    for(int i=0;i<l;i++){
        if(s[i]==':'){
            f=0;continue;
        }
        if(f){
            h2=h2*10+s[i]-'0';
        }else{
            m2=m2*10+s[i]-'0';
        }
    }
    int d=(h2-h1-1)*60;
    d+=60-m1+m2;
    d/=2;
    int t=d/60;
    int r=d%60;
    h1+=t;
    m1+=r;
    //cout<<h1<<" "<<m1<<" "<<1<<endl;
    if(m1>=60){
        h1++;
        m1%=60;
    }
    if(h1<10) printf("0");
    printf("%d:",h1);
    if(m1<10) printf("0");
    printf("%d",m1);
    return 0;
}
