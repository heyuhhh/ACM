//#define LOCAL_DEV
//#define CHECK_ANS
//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#ifdef LOCAL_DEV
#include "Tools.hpp"
#endif
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 100;
int a[maxn];
//leftmost / rightmost pos that don't exist same number
int l0[maxn],r0[maxn];
//leftmost / rightmost pos that don't exist same or bigger number
int l[maxn],r[maxn];

int last_pos[maxn];
int n;
int k;
stack<int> stk;
ll ans;
void solve(int l,int r){
    if (r - l <= 3){
        for (int i=l;i<=r;i++){
            int mx = -1;
            set<int> num;
            for (int j=i;j<=r;j++){
                mx = max(mx,a[j]);
                if (num.count(a[j]))break;
                num.insert(a[j]);
                if (mx - (j - i + 1) <= k)ans ++;
            }
        }
        return;
    }
    int mid = l + r >> 1;
    //mx at left
    int mx = -1;
    int mx_idx = -1;
    int R = r , L;
    for (int i=mid;i>=l;i--){
        if (a[i] > mx){
            mx = a[i];
            mx_idx = i;
        }
        R = min(R,::r0[i]);
        int TR = min(R,::r[mx_idx]);
        L = max(mid+1,mx +i - k - 1);
        ans += max(0,TR - L + 1);
        //if (R <mid+1)break;
    }

    //mx at right
    mx = -1;
    L = l;
    mx_idx = -1;
    for (int i=mid+1;i<=r;i++){
        if (a[i] > mx){
            mx = a[i];
            mx_idx = i;
        }
        L = max(L,::l0[i]);
        int TL = max(L,::l[mx_idx]);
        R = min(mid,i + 1 + k - mx);
        ans += max(0,R - TL + 1);
        //if (L > mid)break;
    }
    solve(l,mid);
    solve(mid+1,r);
}
int main(){
#ifdef LOCAL_DEV
    ofstream fout("input");
    data_generate(fout);
    freopen("input","r",stdin);
    clock_t st = clock();
#endif
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++){scanf("%d",a+i);}
        for (int i=0;i<=n;i++)last_pos[i] = n+1;
        r[n+1] = n;
        for (int i=n;i>=1;i--)r[i] = r0[i] = min(r[i+1],last_pos[a[i]]-1),last_pos[a[i]] = i;
        for (int i=0;i<=n;i++)last_pos[i] = 0;
        l[0] = 1;
        for (int i=1;i<=n;i++)l[i] = l0[i] = max(l[i-1],last_pos[a[i]] + 1),last_pos[a[i]] = i;
        a[0] = a[n+1] = n + 2;//inf
        while (!stk.empty())stk.pop();
        stk.push(0);
        for (int i=1;i<=n;i++){
            while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
            l[i] = max(l[i],stk.top() + 1);
            stk.push(i);
        }
        while (!stk.empty())stk.pop();
        stk.push(n+1);
        for (int i=n;i>=1;i--){
            while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
            r[i] = min(r[i],stk.top() - 1);
            stk.push(i);
        }
        ans = 0;
        solve(1,n);
#ifdef LOCAL_DEV
        cerr<<ans<<" vs "<<ANS.front()<<endl;
        assert(ans == ANS.front());
        ANS.pop();
#endif
        printf("%lld\n",ans);
    }
#ifdef LOCAL_DEV
    clock_t ed = clock();
    cerr<<"solution duration: "<< 1.0 * (ed - st) / CLOCKS_PER_SEC<<endl;
#endif
    return 0;
}
