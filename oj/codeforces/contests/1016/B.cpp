#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int n,m,q;
char s[N],t[N];
int f[N],c[N];
int lowbit(int x){
    return x&-x;
}
void add(int p,int val){
    for(int i=p;i<=n;i+=lowbit(i)) {
        c[i]+=val;
    }
}
int query(int p){
    int ans = 0;
    for(int i=p;i>=1;i-=lowbit(i)){
        ans+=c[i];
    }
    return ans ;
}
int solve(int l,int r){
    if(r-m+1<l) return 0;
    return query(r-m+1) - query(l-1);
}
int main(){
    scanf("%d%d%d", &n, &m, &q);
    scanf("%s%s", s + 1, t + 1);
    for (int i = 1;i <= n ;i++) {
        int cnt = 1;
        for(int j = i ;j <= n; j++) {
            if(s[j]==t[cnt]){
                cnt++;
                if(cnt>m){
                    f[i]++;
                    break ;
                }
            } else break ;
        }
    }
    for (int i = 1;i <= n ;i++) {
        add(i,f[i]);
    }
    while(q--) {
        int l ,r;
        scanf("%d%d", &l, &r);
        printf("%d\n", solve(l,r));
    }
    return 0;
}
