#include<cstdio>
const int N=50010;
int Case,n,i,x,a[N],b[N],ans[N],pre[N],nxt[N],f[N],g[N],used[N],bit[N];
inline void up(int&a,int b){if(f[a]<f[b])a=b;}
inline void build(){
  int i,j,k;
  for(i=nxt[0];i<=n+1;i=nxt[i]){
    used[i]=0;
    k=0;
    for(j=a[i];j;j-=j&-j)up(k,bit[j]);
    f[i]=f[k]+1;
    g[i]=k;
    for(j=a[i];j<=n+2;j+=j&-j)up(bit[j],i);
  }
  for(i=nxt[0];i<=n+1;i=nxt[i])for(j=a[i];j<=n+2;j+=j&-j)bit[j]=0;
  for(i=n+1;i;i=g[i])used[i]=1;
}
int main(){
  scanf("%d",&Case);
  while(Case--){
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]),a[i]++;
    a[0]=1;
    a[n+1]=n+2;
    for(i=0;i<=n+1;i++)pre[i]=i-1,nxt[i]=i+1,bit[i]=used[i]=0;
    bit[n+2]=0;
    for(i=1;i<=n;i++)scanf("%d",&b[i]);
    build();
    for(i=n;i;i--){
      ans[i]=f[n+1]-1;
      x=b[i];
      pre[nxt[x]]=pre[x];
      nxt[pre[x]]=nxt[x];
      if(used[x])build();
    }
    for(i=1;i<=n;i++)printf("%d%c",ans[i],i<n?' ':'\n');
  }
}