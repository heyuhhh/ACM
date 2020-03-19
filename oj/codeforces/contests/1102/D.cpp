#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
int n;
char s[N];
int cnt[N],a[N];
int main(){
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++) a[i+1]=s[i]-'0',cnt[a[i+1]]++;
    int lev = n/3;
    if(cnt[0]>lev){
        int fir;
        if(cnt[1]>=cnt[2]) fir=2;
        else fir=1;
        for(int i=n;i>=1;i--){
            if(cnt[0]==lev) break ;
            if(!a[i]){
                cnt[fir]++;
                cnt[0]--;
                a[i]=fir;
                if(cnt[fir]>=lev) fir = 3-fir;
            }
        }
    }else if(cnt[0]<lev){
        int fir;
        if(cnt[1]>cnt[2]) fir=1;
        else fir = 2;
        for(int i=1;i<=n;i++){
            if(cnt[0]==lev) break ;
            if(a[i]==fir){
                cnt[fir]--;
                cnt[0]++;
                a[i]=0;
                if(cnt[fir]<=lev) fir=3-fir,i=0;
            }
        }
    }
    if(cnt[1]<lev){
        for(int i=1;i<=n;i++){
            if(cnt[1]>=lev) break;
            if(a[i]==2){
                cnt[2]--;
                cnt[1]++;
                a[i]=1;
            }
        }
    }else if(cnt[1]>lev){
        for(int i=n;i>=1;i--){
            if(cnt[1]<=lev) break ;
            if(a[i]==1){
                cnt[1]--;
                cnt[2]++;
                a[i]=2;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<a[i];
    return 0;
}
