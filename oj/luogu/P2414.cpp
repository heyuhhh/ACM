#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
char s[N];
int pos[N],head[N],fa[N],in[N],out[N],ans[N];
int tot,num;
queue <int> q;
struct Edge{
    int v,next,id;
}e[N<<1];
void adde(int u,int v,int id){
    e[tot].v=v;e[tot].next=head[u];e[tot].id=id;head[u]=tot++;
}
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
    void insert(char *s){
        int l=strlen(s);
        int u=0;
        for(int i=0;i<l;i++){
            if(s[i]=='P'){
                pos[++num]=u;
            }else if(s[i]=='B'){
                u=fa[u];
            }else{
                int idx=s[i]-'a';
                if(!ch[u][idx]) ch[u][idx]=newnode();
                fa[ch[u][idx]]=u;u=ch[u][idx];
            }
        }
    }
    void Getfail(){
        while(!q.empty()) q.pop();
        for(int i=0;i<26;i++){
            if(ch[0][i]) q.push(ch[0][i]),adde(0,ch[0][i],1);
        }
        while(!q.empty()){
            int cur=q.front();q.pop();
            for(int i=0;i<26;i++){
                if(ch[cur][i]){
                    fail[ch[cur][i]]=ch[fail[cur]][i];
                    q.push(ch[cur][i]);
                    adde(ch[fail[cur]][i],ch[cur][i],1);
                }else{
                    ch[cur][i]=ch[fail[cur]][i];
                }
            }
        }
    }
}ac;
int dfn;
void dfs(int u,int pa){
    in[u]=++dfn;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v!=pa) dfs(v,u);
    }
    out[u]=dfn;
}
int c[N];
int lowbit(int x){
    return x&(-x);
}
void add(int pos,int val){
    for(int i=pos;i<=N-5;i+=lowbit(i)) c[i]+=val;
}
int query(int l){
    int ans=0;
    for(int i=l;i>0;i-=lowbit(i)) ans+=c[i];
    return ans ;
}
int main(){
    scanf("%s",s);
    memset(head,-1,sizeof(head));tot=0;
    ac.init();
    ac.insert(s);
    ac.Getfail();
    dfs(0,-1);
    memset(head,-1,sizeof(head));tot=0;
    int q;cin>>q;
    for(int i=1,x,y;i<=q;i++){
        scanf("%d%d",&x,&y);
        adde(y,x,i);
    }
    int l=strlen(s);
    int cnt=0,u=0;;
    for(int i=0;i<l;i++){
        if(s[i]=='B'){
            add(in[u],-1);u=fa[u];
        }else if(s[i]=='P'){
            cnt++;
            int now=pos[cnt];
            for(int j=head[cnt];j!=-1;j=e[j].next){
                int x=pos[e[j].v];
                ans[e[j].id]=query(out[x])-query(in[x]-1);
            }
        }else{
            int idx=s[i]-'a';
            u=ac.ch[u][idx];
            add(in[u],1);
        }
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}
