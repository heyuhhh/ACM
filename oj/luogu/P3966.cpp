#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+205;
int n,tot;
char s[N];
int num[N],Q[N];
queue <int> q;
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
        fail[Size]=0;
        return Size;
    }
    void insert(char *s,int id){
        int l=strlen(s);
        int u=0;
        for(int i=0;i<l;i++){
            int idx=s[i]-'a';
            if(!ch[u][idx]) ch[u][idx]=newnode();
            u=ch[u][idx];
            num[u]++;
        }
       val[id]=u;
    }
    void Getfail(){
        while(!q.empty()) q.pop();
        for(int i=0;i<26;i++){
            if(ch[0][i]) q.push(ch[0][i]);
        }
        while(!q.empty()){
            int cur=q.front();q.pop();
            Q[++tot]=cur;
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
}ac;
int main(){
    cin>>n;
    ac.init();
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        ac.insert(s,i);
    }
    ac.Getfail();
    for(int i=tot;i>=1;i--) num[ac.fail[Q[i]]]+=num[Q[i]];
    for(int i=1;i<=n;i++){
        printf("%d\n",num[ac.val[i]]);
    }
    return 0;
}

