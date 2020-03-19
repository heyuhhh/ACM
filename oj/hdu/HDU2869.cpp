#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 10005,M = 1005,C = 100005;
int n,m;
char s[N];
int check[505];
vector <int> vec[M];
queue <int> q;
struct Aho_Corasick{
    int Size;
    int ch[C][130];
    int val[C];
    int fail[C];
    void init(){
        Size=-1;
        newnode();
    }
    int newnode(){
        memset(ch[++Size],0,sizeof(ch[0]));
        val[Size]=fail[Size]=0;
        return Size;
    }
    void insert(char *s,int id){
        int l=strlen(s);
        int u=0;
        for(int i=0;i<l;i++){
            int idx=s[i];
            if(!ch[u][idx]) ch[u][idx]=newnode();
            u=ch[u][idx];
        }
        val[u]=id;
    }
    void Getfail(){
        while(!q.empty()) q.pop();
        for(int i=0;i<128;i++){
            if(ch[0][i]) q.push(ch[0][i]);
        }
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(int i=0;i<128;i++){
                if(ch[cur][i]){
                    fail[ch[cur][i]]=ch[fail[cur]][i];
                    q.push(ch[cur][i]);
                }else{
                    ch[cur][i]=ch[fail[cur]][i];
                }
            }

        }
    }
    int query(char *s){
        int ans = 0,u = 0;
        memset(check,0,sizeof(check));
        int l=strlen(s);
        for(int i=0;i<l;i++){
            int idx = s[i];
            int cur = ch[u][idx];
            int tmp=cur;
            while(tmp && val[tmp]>=0){
                check[val[tmp]]=1;
                tmp=fail[tmp];
            }
            u=cur;
        }
        return ans ;
    }
}ac;
int main(){
    scanf("%d",&n);
    ac.init();
    getchar();
    for(int i=1;i<=n;i++){
        gets(s);
        ac.insert(s,i);
    }
    scanf("%d",&m);
    int tot=0;
    ac.Getfail();
    getchar();
    for(int i=1;i<=m;i++){
        gets(s);
        ac.query(s);
        for(int j=1;j<=n;j++){
            if(check[j]) vec[i].push_back(j);
        }
        if((int)vec[i].size()>0) tot++;
        else continue ;
        printf("web %d:",i);
        sort(vec[i].begin(),vec[i].end());
        for(int j=0;j<(int)vec[i].size();j++) printf(" %d",vec[i][j]);
        printf("\n");
    }
    printf("total: %d\n",tot);
    return 0;
}
