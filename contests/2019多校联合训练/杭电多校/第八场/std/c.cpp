#include<bits/stdc++.h>
#define maxn 1000030

using namespace std;
typedef long long ll;
const ll m=100000;
ll a[maxn][10],ans[10][maxn],r,d,k,query,c[10],sum,cc;
bool check(ll x,ll y){
    if (x<0&&y>=0) return 1;
    if (x>y&&x>=0&&x<m) return 1;
    return 0;
}

int main(){
    for (int i=1;i<m*10;i++){
        for (int j=0;j<10;j++) a[i][j]=a[i/10][j];
        a[i][i%10]++;
    }
    for (d=1;d<10;d++){
        r=1;
        for (int i=0;i<m*d;i++)
            if (check(r,r-m/2+m*a[i][d])){
                ++cc;
                for (int j=0;j<m;j++){
                    r+=a[i][d]+a[j][d]-1;
                    if (r==0) ans[d][c[d]++]=m*i+j;
                }
            }
            else r+=m*a[i][d]-m/2;
    }
    scanf("%d",&query);
    assert(query >= 1 && query <= 1500);
    while (query--){
        scanf("%d%lld",&d,&k);
        assert(d >= 1 && d <= 9);
        assert(k >= 0 && k <= 1000000000000000000LL);
        r=c[d]-1; while (r>=0&&ans[d][r]>k) r--;
        if (r>=0) cout << ans[d][r] << endl; else cout << 0 << endl;
    }
    return 0;
}
