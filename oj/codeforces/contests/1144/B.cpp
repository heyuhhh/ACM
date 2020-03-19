#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2005;
int a[N];
int n ;
int cnt1, cnt2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector <int> b, c;
    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        if(a[i] & 1)
            cnt1++, b.push_back(a[i]);
        else
            cnt2++, c.push_back(a[i]);
        }
    if(abs(cnt1 - cnt2) <= 1) {
        cout << 0;
        return 0;
    }
    ll ans = 0;
    if(cnt2 > cnt1)
        swap(b, c) , swap(cnt1,cnt2);
    int d = cnt1 - cnt2 - 1;
    sort(b.begin(), b.end());
    int cnt = 0 ;
    for(auto v : b) {
        cnt++;
        ans += v;
        if(cnt >= d)
            break ;
    }
    cout << ans;
    return 0 ;
}
