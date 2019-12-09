#include<stdio.h>
int min(int x,int y){return x<y?x:y;}
char s[1000001];
int d[1000001];
int main(){
    int T,left,i,k;
    long long an1,an2;
    scanf("%d",&T);
    while(T--){
        an1=an2=0;
        scanf("%s",s);
        for(i=1,left=0;s[i];i++){
            if(i<left+d[left])
                k=min(d[i-left],left+d[left]-i);
            else
                k=0;
            for(;s[i+k];k++){
                if(s[i+k]!=s[k])break;
            }
            d[i]=k;
            if(i+k>left+d[left])left=i;
        }
        int len=i;
        for(i=1;i<len;i++){
            if(d[i]+i==len)an1+=len-i;
            else an1+=d[i]+1;
        }
        printf("%lld\n",an1);
    }
}
