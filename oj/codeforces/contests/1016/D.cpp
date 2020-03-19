#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
ll a[N], b[N];
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    ll cur = 0;
    for(int i = 1; i <= n; i++)
        cin >> a[i], cur ^= a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i], cur ^= b[i];
    if(cur != 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << '\n';
    cur = a[1];
    for(int i = 2; i <= m; i++)
        cur ^= b[i];
    cout << cur;
    for(int i = 2; i <= m; i++)
        cout << ' ' << b[i];
    cout << '\n';
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j == 1)
                cout << a[i];
            else
                cout << ' ' << 0;
        }
        cout << '\n';
    }
    return 0;
}
