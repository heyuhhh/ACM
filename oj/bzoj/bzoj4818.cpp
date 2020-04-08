/*
 * Author:  heyuhhh
 * Created Time:  2020/4/8 20:58:02
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 100 + 5, M = 2e7 + 5, MOD = 20170408;

struct matrix {
    ll A[N][N];
    int n,m;
    matrix(){
        memset(A,0,sizeof(A));
    }
    void Print(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
matrix operator * (const matrix &a,const matrix &b){
    matrix ans;
    ans.n=a.n;ans.m=b.m;
    for(int i=1;i<=ans.n;i++){
        for(int j=1;j<=ans.m;j++){
            for(int k=1;k<=b.n;k++){
                ans.A[i][j]=(ans.A[i][j]+a.A[i][k]*b.A[k][j]%MOD)%MOD;
            }
        }
    }
    return ans ;
}
matrix operator + (const matrix &a,const matrix &b){
    matrix ans;
    ans.n=a.n;ans.m=a.m;
    for(int i=1;i<=ans.n;i++){
        for(int j=1;j<=ans.m;j++){
            ans.A[i][j]=(a.A[i][j]+b.A[i][j])%MOD;
        }
    }
    return ans ;
}
matrix qp_Mat(matrix a,ll b){
    matrix ans;
    ans.n=ans.m=a.n;
    for(int i=1;i<=ans.n;i++) ans.A[i][i]=1;
    while(b){
        if(b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans ;
} 

int n, m, p, cnt;
int a[N], b[N];
int pri[M];
bool chk[M];
void init() {
    for(int i = 2; i <= m; i++) {
        if(!chk[i]) pri[++cnt] = i, ++b[(i - 1) % p + 1];
        for(int j = 1; j <= cnt && i * pri[j] <= m; j++) {
            chk[i * pri[j]] = 1;
        }
    }
} 

int gao(int *a) {
    matrix A, B;
    A.n = 1, A.m = p;
    A.A[1][1] = 1;
    for(int i = 2; i <= p; i++) A.A[1][i] = 0;
    B.n = p, B.m = p;
    for(int i = 1; i <= p; i++) {
        int now = p, j = i;
        while(1) {
            B.A[i][j++] = a[now--];
            if(j > p) j -= p;              
            if(now == 0) break;
        }
    }
    matrix ans = A * qp_Mat(B, n);
    int res = ans.A[1][1];      
    return res;
}

void run() {
    cin >> n >> m >> p;
    init();
    int r = m % p;
    for(int i = 1; i <= p; i++) {
        a[i] = m / p;
        if(i <= r) ++a[i];
    }
    int ans = gao(a);
    for(int i = 1; i <= p; i++) a[i] -= b[i];
    ans -= gao(a);
    if(ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
