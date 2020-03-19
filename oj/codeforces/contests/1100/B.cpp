#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,m;
int cnt[N],a[N];
int main(){
    int num = 0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        if(cnt[a[i]]==1) num++;
        if(num==n){
            printf("1");
            for(int j=1;j<=n;j++){
                cnt[j]--;
                if(!cnt[j]) num--;
            }
        }else printf("0");
    }
    return 0;
}
