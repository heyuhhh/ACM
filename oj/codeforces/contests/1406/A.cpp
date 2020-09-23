// Author : heyuhhh
// Created Time : 2020/09/12 21:45:51
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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    vector<int> cnt(101);
    for (int i = 0; i < n; i++) {
        ++cnt[a[i]];
    }
    int tot = 0;
    for (int i = 0; i < 101; i++) {
        if (cnt[i] >= 2) {
            continue;
        }
        if (cnt[i] == 1) {
            if (tot == 0) {
                ++tot;
                ans += i;
            } else {
                continue;
            }
        } else {
            ans += (2 - tot) * i;
            tot += 2;
        }
        if (tot >= 2) break;
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
    int T; cin >> T; while(T--)
    run();
    return 0;
}