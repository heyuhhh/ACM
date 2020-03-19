#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000005;
int n,m;
char s[N];
int dp[N];
struct Aho_Corasick{
    int Size;
    int ch[N][30];
    int val[N];
    int fail[N];
    void init(){
        Size=-1;
        newnode();
    }
    int newnode(){
        memset(ch[++Size],0,sizeof(ch[0]));
        val[Size]=fail[Size]=0;
        return Size;
    }
    void insert(char *s){
        int l=strlen(s);
        int u=0;
        for(int i=0;i<l;i++){
            int idx=s[i]-'a';
            if(!ch[u][idx]) ch[u][idx]=newnode();
            u=ch[u][idx];
        }
        val[u]++;
    }
    int query(char *s,int id){
        int l=strlen(s+1);
        dp[0]=id;
        int ans=0,u=0;
        for(int i=0;i<=l;i++){
            if(dp[i]!=id&&i) continue ;
            u=0;
            for(int j=i+1;j<=l;j++){
                int idx=s[j]-'a';
                if(ch[u][idx]==0) break ;
                u=ch[u][idx];
                if(val[u]) ans=max(ans,j),dp[j]=id;
            }
        }
        return ans ;
    }
}ac;
int main(){
    cin>>n>>m;
    ac.init();
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        ac.insert(s);
    }
    for(int i=1;i<=m;i++){
        scanf("%s",s+1);
        printf("%d\n",ac.query(s,i));
    }

    return 0;
}

