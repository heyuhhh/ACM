#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005,MAX = 1000;
int n;
int a[N];
int cnt[N];
int mp[N][N];
int main(){
    cin>>n;
    for(int i=1;i<=n*n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
    if(n&1){
        int tmp=0;
        for(int i=1;i<=MAX;i++){
            if(cnt[i]&1) tmp++;
        }
        if(tmp>1){
            printf("NO");
            return 0;
        }
        for(int i=1;i<=n/2;i++){
            for(int j=1;j<=n/2;j++){
                for(int k=1;k<=MAX;k++){
                    if(cnt[k]/4>=1){
                        cnt[k]-=4;
                        mp[i][j]=k;
                        break;
                    }
                }
            }
        }
        for(int j=1;j<=n/2;j++){
            int i=n/2+1;
            for(int k=1;k<=MAX;k++){
                if(cnt[k]/2>=1){
                    cnt[k]-=2;
                    mp[i][j]=k;
                    break ;
                }
            }
        }
        for(int i=1;i<=n/2;i++){
            int j=n/2+1;
            for(int k=1;k<=MAX;k++){
                if(cnt[k]/2>=1){
                    cnt[k]-=2;
                    mp[i][j]=k;
                    break ;
                }
            }
        }
        tmp=0;
        for(int i=1;i<=MAX;i++){
            if(cnt[i]){
                tmp++;
                mp[n/2+1][n/2+1]=i;
            }
        }
        if(tmp>1){
            printf("NO");
            return 0;
        }
        for(int i=1;i<=n/2+1;i++){
            for(int j=n/2+2;j<=n;j++){
                int k=2*(n/2+1)-j;
                mp[i][j]=mp[i][k];
            }
        }
        for(int i=n/2+2;i<=n;i++){
            for(int j=1;j<=n;j++){
                int k=2*(n/2+1)-i;
                mp[i][j]=mp[k][j];
            }
        }
        puts("YES");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%d ",mp[i][j]);
            }
            printf("\n");
        }
    }else{
        int tmp=0;
        for(int i=1;i<=MAX;i++) if(cnt[i]&1) tmp++;
        if(tmp){
            printf("NO");
            return 0;
        }
        for(int i=1;i<=n/2;i++){
            for(int j=1;j<=n/2;j++){
                for(int k=1;k<=MAX;k++){
                    if(cnt[k]/4>=1){
                        cnt[k]-=4;
                        mp[i][j]=k;
                        break ;
                    }
                }
            }
        }
        for(int k=1;k<=MAX;k++){
            if(cnt[k]) tmp++;
        }
        if(tmp){
            printf("NO");
            return 0;
        }
        for(int i=1;i<=n/2;i++){
            for(int j=n/2+1;j<=n;j++){
                int k=n+1-j;
                mp[i][j]=mp[i][k];
            }
        }
        for(int i=n/2+1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int k=n+1-i;
                mp[i][j]=mp[k][j];
            }
        }
        puts("YES");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%d ",mp[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
