// Author : heyuhhh
// Created Time : 2021/01/16 20:01:15
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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> preA(n + 1), preB(n + 1);
    for (int i = 0; i < n; i++) {
        preA[i + 1] = max(preA[i], a[i]);
    }
    for (int i = 0; i < n; i++) {
        preB[i + 1] = max(preB[i], b[i]);
    }
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        ll res = max(pre[i], 1ll * b[i] * preA[i + 1]);
        pre[i + 1] = max(pre[i], 1ll * b[i] * preA[i + 1]);
        cout << res << '\n';
    }
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