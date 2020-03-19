#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 500005,M = 26;
int t;
int n;
queue <int> q;
char s[55],str[1000005];
struct Aho_Corasick{
    int Size;
    int ch[N][M];
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
    void Getfail(){
        while(!q.empty()) q.pop();
        for(int i=0;i<26;i++){
            if(ch[0][i]) q.push(ch[0][i]);
        }
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(int i=0;i<26;i++){
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
        int l=strlen(s);
        for(int i=0;i<l;i++){
            int idx = s[i]-'a';
            int cur = ch[u][idx];
            int tmp=cur;
            while(tmp && val[tmp]>=0){
                ans+=val[tmp];
                val[tmp]=-1;
                tmp=fail[tmp];
            }
            u=cur;
        }
        return ans ;
    }
}ac;
int main(){
    scanf("%d",&t);
    while(t--){
        ac.init();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            //memset(s,0,sizeof(s));
            scanf("%s",s);
            ac.insert(s);
            int l=strlen(s);
        }
        ac.Getfail();
        //memset(str,0,sizeof(str));
        scanf("%s",str);
        int ans = ac.query(str);
        printf("%d\n",ans);
    }
    return 0;
}
