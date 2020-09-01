// Author : heyuhhh
// Created Time : 2020/07/16 16:59:43
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
const int N = 2000 + 5;

void run() {
    int n, p; cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    vector<int> ans;
    for (int x = 1; x < a[n - 1]; x++) {
        int now = 0;
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            while (now < n && a[now] <= x + i - 1) ++now;
            if (now < i || (now - i + 1) % p == 0) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            ans.push_back(x);
        }
    }
    cout << sz(ans) << '\n';
    for (auto it : ans) {
        cout << it << ' ' ;
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