#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  =  2e5 +5 ;
int n;
int a[N];
int vis[N];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n ; i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int cnt = 1;
    a[0] = -1;a[n + 1] = -1;
    for(int i = 2; i <= n; i++) {
        if(a[i] == a[i-1]) cnt++;
        else cnt = 1;
        if(cnt>2){
            cout << "NO";
            return 0;
        }
    }
    vector <int> ans1,ans2;
    for(int i = 1;i <= n; i++) {
        if(!vis[i] && a[i] != a[i - 1]){
            ans1.push_back(a[i]);
            vis[i] = 1;
        }
    }
    for(int i = n ; i >= 1; i--){
        if(!vis[i]) {
            ans2.push_back(a[i]);
        }
    }
    cout << "YES" << '\n';
    cout << ans1.size() << '\n';
    for(auto v:ans1){
        cout << v << ' ';
    }
    cout << '\n';
    cout << ans2.size() << '\n';
    for(auto v:ans2) cout << v << ' ';
    return 0;
}
