// Author : heyuhhh
// Created Time : 2020/11/08 20:05:45
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int Max = 0, ans;
    for (int k = 2; k <= 1000; k++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) if (a[i] % k == 0) {
            ++cnt;
        }
        if (cnt > Max) {
            Max = cnt;
            ans = k;
        }
    }
    cout << ans << '\n';
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