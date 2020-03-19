#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
const int N = 2e5 +5 ,MAX = 1e18;
int n;
int a[N];
int cnt[N];
int main( ) {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n ; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    int mx = -1,st;
    for(int i = 0; i < N; i++){
        if(cnt[i] > mx){
            mx = cnt[i];
            st = i;
        }
    }
    int pos;
    for(int i = 1; i <=n ;i++) {
        if(a[i] == st) {
            pos = i;
            break ;
        }
    }
    vector <pair<int,pair<int,int> > > ans;
    for(int i = pos + 1;i <= n; i++) {
        if(a[i] > st){
            ans.emplace_back(mp(2,mp(i,i-1)));
        }else if(a[i] < st) {
            ans.emplace_back(mp(1,mp(i,i-1)));
        }
    }
    for(int i = pos-1; i >= 1 ; i--) {
        if(a[i] > st) {
            ans.emplace_back(mp(2,mp(i,i+1)));
        }else if(a[i] < st) {
            ans.emplace_back(mp(1,mp(i,i+1)));
        }
    }
    cout << ans.size() << '\n';
    for(auto v : ans) {
        cout << v.first << ' ' << v.second.first << ' ' << v.second.second << '\n' ;
    }
    return 0;
}
