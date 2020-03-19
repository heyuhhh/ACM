#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n;
int a[N], b[N], c[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++)
        cin >> a[i];
    b[1] = 0;
    for(int i = 1; i < n; i++) {
        b[i + 1] = b[i] + a[i];
    }
    int mn = *min_element(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++)
        b[i] += 1 - mn;
    for(int i = 1; i <= n; i++)
        c[i] = b[i];
    sort(c + 1, c + n + 1);
    int check = 0;
    for(int i = 1; i <= n; i++) {
        if(c[i] != i)
            check = 1;
    }
    if(check) {
        cout << -1;
    } else {
        for(int i = 1; i <= n; i++)
            cout << b[i] << " ";
    }
    return 0;
}
