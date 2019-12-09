#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5e5+5,lim=3e5;
int a[maxn],b[maxn],c[maxn],d[maxn];
int sa,sb,sc;
char s[maxn];
int check(int c[],int sc,int a[],int sa,int b[],int sb){
    int i;
    for (i=0;i<lim;i++) if (c[i]!=a[i]){
        if (c[i]<a[i]) return -1;
        break;
    }
    for (i=0;i<lim;i++) d[i]=c[i]-a[i];
    for (i=lim-1;i;i--) if (d[i]<0){
        d[i-1]--; d[i]+=10;
    }
    int t=0;
    while (!d[t]&&t<lim) t++;
    if (t==lim) return -1;
    for (i=0;i<sb;i++) if (d[t+i]!=b[i]) return -1;
    for (i=sb;i<lim;i++) if (d[t+i]) return -1;
    return lim-sb-t;
}
int main(){
    int tt;
    int i,t;
    scanf("%d",&tt);
    while (tt--){
        memset(a,0,sizeof(a));
        scanf("%s",s);
        for (i=0;s[i];i++) a[i+1]=s[i]-'0';
        sa=i;
        memset(b,0,sizeof(b));
        scanf("%s",s);
        for (i=0;s[i];i++) b[i+1]=s[i]-'0';
        sb=i;
        memset(c,0,sizeof(c));
        scanf("%s",s);
        for (i=0;s[i];i++) c[i+1]=s[i]-'0';
        sc=i;
        if ((t=check(c+1,sc,a+1,sa,b+1,sb))!=-1){
            printf("%d %d %d\n",lim-sa,t,lim-sc);
            continue;
        }
        if ((t=check(c+1,sc,a,sa+1,b+1,sb))!=-1){
            printf("%d %d %d\n",lim-sa-1,t,lim-sc);
            continue;
        }
        if ((t=check(c+1,sc,b+1,sb,a+1,sa))!=-1){
            printf("%d %d %d\n",t,lim-sb,lim-sc);
            continue;
        }
        if ((t=check(c+1,sc,b,sb+1,a+1,sa))!=-1){
            printf("%d %d %d\n",t,lim-sb-1,lim-sc);
            continue;
        }
        puts("-1");
    }
    return 0;
}