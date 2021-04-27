// Author : heyuhhh
// Created Time : 2020/09/19 20:24:04
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
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 2; i < n; i++) {
        if (a[i].fi == a[i].se && a[i - 1].fi == a[i - 1].se && a[i - 2].fi == a[i - 2].se) {
            cout << "Yes" << '\n';
            return;
        }
    }
    cout << "No" << '\n';
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