#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 ;
int a[N];
int cnt[N];
int n,c,ans=-1;
vector <int> pos[N];
int calc(int x){
    if(x==c) return 0;
    vector <int> vec;
    int len = pos[x].size();
    if(len<=0) return 0;
    vec.push_back(-cnt[pos[x][0]-1]);
    vec.push_back(1);
    for(int i=1;i<len;i++){
        vec.push_back(-cnt[pos[x][i]-1]+cnt[pos[x][i-1]]);
        vec.push_back(1);
        if(i==len-1) vec.push_back(-cnt[n]+cnt[pos[x][i]]);
    }
    int tot = 0,sum = 0,l = vec.size();
    for(int i=0;i<l;i++){
        sum+=vec[i];
        if(sum>=tot){
            tot=sum;
        }else if(sum<0) sum=0;
    }
    return max(tot,sum);
}
int main(){
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[i]=cnt[i-1]+(a[i]==c);
        pos[a[i]].push_back(i);
    }
    for(int i=1;i<=N-5;i++){
        ans=max(calc(i)+cnt[n],ans);
    }
    printf("%d",ans);
    return 0;
}

