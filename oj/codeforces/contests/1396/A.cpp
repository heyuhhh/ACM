// Author : heyuhhh
// Created Time : 2020/09/17 09:59:05
#include<bits/stdc++.h>
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
const int N = 1e5 + 5;
void run() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 1 << ' ' << 1 << '\n' << -a[0] << '\n';
        cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
        cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
        return;
    }
    cout << 1 << ' ' << n - 1 << '\n';
    for (int i = 0; i < n - 1; i++) {
        int x = a[i] % n;
        a[i] += 1ll * x * (n - 1);
        if (i) cout << ' ';
        cout << 1ll * x * (n - 1);
    }
    cout << '\n';
    cout << 2 << ' ' << n << '\n';
    for (int i = 1; i < n; i++) {
        int x = a[i] % n;
        a[i] += 1ll * x * (n - 1);
        if (i > 1) cout << ' ';
        cout << 1ll * x * (n - 1);
    }
    cout << '\n';
    cout << 1 << ' ' << n << '\n';
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << -a[i];
    }
    cout << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}