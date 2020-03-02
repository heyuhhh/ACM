#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int MAXN = 1e5+5,MAXM = 1e6+5,MOD = 998244353,INF = 0x3f3f3f3f,N=2e5;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const db eps = 1e-7;
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define mid l + ((r-l)>>1)
#define pii pair<int,int>
#define vii vector<pii>
#define vi vector<int>
#define x first
#define y second
using namespace std;

int n,k,sta[MAXN],cnt[10];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        int m,x;
        cin>>m;
        for(int j=1;j<=m;j++){
            cin>>x;
            sta[x] |= (1<<(i-1));
        }
    }
    for(int i=1;i<=n;i++){
        if(sta[i])cnt[sta[i]]++;
    }
    if(k==1){
        cout<<cnt[1]<<'\n';
    }else if(k==2){
        cout << cnt[1] + cnt[2] + cnt[3] - min(cnt[1],cnt[2])<<'\n';
    }else{
        int ans=cnt[7];
        int c2 = cnt[3] + cnt[5] + cnt[6];
        cout << c2 << '\n';
        //c2 + max
        vector <int> q;
        q.push_back(cnt[1]); q.push_back(cnt[2]); q.push_back(cnt[4]);
        sort(q.begin(), q.end());
        while(c2 > 0 && q[2] > 0) {
            cout << q[2] << '\n';
            --q[2]; --c2; ++ans;
            sort(q.begin(), q.end());
        }
        for(int i = 0; i < 3; i++) cout << q[i] << ' ';
        cout << '\n';
        ans += c2 + q[2];
        cout << ans << '\n';
    }
    return 0;
}
