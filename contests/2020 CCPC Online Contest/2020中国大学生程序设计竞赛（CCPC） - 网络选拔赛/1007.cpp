// Author : heyuhhh
// Created Time : 2020/09/20 12:13:21
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

int _;

void run() {
    ++_;
    string s;
    cin >> s;
    int n = s.length();
    vector<int> cnt(26);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ++cnt[s[i] - 'a'];
    }
    for (int i = 0; i < 26; i++) {
        ans = max(ans, cnt[i]);
    }    
    cout << "Case #" << _ << ": ";
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