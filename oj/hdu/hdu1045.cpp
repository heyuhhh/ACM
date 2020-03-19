#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 20 ;
int n,cnt=0,ans=0,tot=0;
int map1[N][N],map2[N][N],match[N],link[N][N],check[N];
char tmp[N][N] ;

inline void init(){
    cnt=0;tot=0;ans=0;
    memset(map1,0,sizeof(map1));memset(map2,0,sizeof(map2));
    memset(match,-1,sizeof(match));memset(link,0,sizeof(link));
}

inline int dfs(int x){
    for(int j=1;j<=cnt;j++){
        if(!check[j] && link[x][j]){
            check[j]=1;
            if(match[j]==-1 || dfs(match[j])){
                match[j]=x;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    while(~scanf("%d",&n)){
        if(n==0) break ;
        init();
        getchar();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) scanf("%c",&tmp[i][j]);
            getchar();
        }
        int k;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(tmp[i][j]=='.'){
                    tot++;
                    for(k=j;k<=n;k++){
                        j=k;
                        if(tmp[i][k]=='X') break ;
                        map1[i][k]=tot;
                    }
                }
            }
        }
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++){
                if(tmp[i][j]=='.'){
                    cnt++;
                    for(k=i;k<=n;k++){
                        i=k;
                        if(tmp[k][j]=='X') break;
                        map2[k][j]=cnt;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(tmp[i][j]=='.') link[map1[i][j]][map2[i][j]]=1;
            }
        }
        for(int i=1;i<=tot;i++){
            memset(check,0,sizeof(check));
            if(dfs(i)) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
} 
