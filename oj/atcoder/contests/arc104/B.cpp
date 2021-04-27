// Author : heyuhhh
// Created Time : 2020/10/03 20:04:01
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
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int l = 0; l < n; l++) {
        vector<int> cnt(4);
        for (int r = l; r < n; r++) {
            if (s[r] == 'A') ++cnt[0];
            if (s[r] == 'T') ++cnt[1];
            if (s[r] == 'C') ++cnt[2];
            if (s[r] == 'G') ++cnt[3];
            if (cnt[0] == cnt[1] && cnt[2] == cnt[3]) ++ans;
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