#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=6e5+5;
const int N=6e5+3;
int a[maxn],b[maxn],cnt[maxn],ans,n,r;
vector <int> h[maxn];
multiset <int> s;
void add(int x){
    auto p=s.find(cnt[x]);
    s.erase(p); cnt[x]++;
    s.insert(cnt[x]);
}
void del(int x){
    auto p=s.find(cnt[x]);
    s.erase(p); cnt[x]--;
    s.insert(cnt[x]);
}
int main(){
    cin >> n >> r;
    for (int i=0;i<n;i++){
        cin >> a[i] >> b[i];
        a[i]+=r*2; b[i]+=r*2;
    }
    for (int i=0;i<n;i++){
        h[a[i]-r].pb(b[i]);
        h[a[i]].pb(b[i]);
        h[a[i]+r].pb(b[i]);
        cnt[b[i]]++; cnt[b[i]-r]++; cnt[b[i]+r]++;
    }
    for (int i=r;i<=N-r;i++) s.insert(cnt[i]);
    for (int i=r;i<=N-r;i++){
        int ret=(int)h[i].size();
        for (auto x:h[i]) del(x),del(x-r),del(x+r);
        auto p=s.rbegin();
        ans=max(ans,ret+(*p));
        for (auto x:h[i]) add(x),add(x-r),add(x+r);
    }
    cout << ans << endl;
}
