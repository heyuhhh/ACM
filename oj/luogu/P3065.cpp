#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,tot;
int val[1000005],check[30005],vis[30],head[30],in[30],Not[30005];
char s[300005];
string str[30005];
struct Edge{
    int u,v,next;
}e[1000005];
void adde(int u,int v){
    e[tot].u=u;e[tot].v=v;e[tot].next=head[u];head[u]=tot++;
}
struct Trie{
    char node;
    int son,left;
    Trie(){son=left=-1;}
}tre[1000005];
void init(){
    tre[0].son=tre[0].left=-1;tot=1;
}
void insert(int now){
    int j,u=0;
    int l = strlen(s);
    for(int i=0;i<l;i++){
        bool flag=false;
        for(j=tre[u].son;j!=-1;j=tre[j].left){
            if(tre[j].node==s[i]){
                flag=true;
                break ;
            }
        }
        if(!flag){
            j=tot++;
            tre[j].left=tre[u].son;
            tre[u].son=j;
            tre[j].node=s[i];
            tre[j].son=-1;
        }
        u=j;
    }
    val[u]=1;
}
int Use(string S){
    memset(head,-1,sizeof(head));tot=0;
    memset(in,0,sizeof(in));memset(vis,0,sizeof(vis));
    int l=S.length();
    int u=0,j,Next;
    for(int i=0;i<l;i++){
        for(j=tre[u].son;j!=-1;j=tre[j].left){
            int u=S[i]-'a',v=tre[j].node-'a';
            if(u==v){
                Next=j;
                continue ;
            }
            adde(u,v);vis[u]=vis[v]=1;in[v]++;
        }
        u=Next;
        if(val[u]&&i!=l-1) return 0;
    }
    return 1;
}
int top_sort(){
    queue <int> q;
    int cnt = 0,num = 0;
    for(int i=0;i<26;i++) if(!in[i]&&vis[i]) q.push(i),cnt++;
    for(int i=0;i<26;i++) if(vis[i]) num++;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(--in[v]==0) q.push(v),cnt++;
        }
    }
    return cnt==num;
}
int main(){
    cin>>n;
    init();
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        str[i]=s;
        insert(i);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(Use(str[i])&&top_sort()) check[i]=1,ans++;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++){
        if(check[i]) cout<<str[i]<<'\n';
    }
    return 0;
}

