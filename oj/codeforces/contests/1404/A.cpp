// Author : heyuhhh
// Created Time : 2020/09/16 11:04:53
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < k; i++) {
        bool has_0 = false, has_1 = false;
        for (int j = i; j < n; j += k) {
            if (s[j] == '0') has_0 = true;
            if (s[j] == '1') has_1 = true;
        }
        if (has_0 && has_1) {
            cout << "NO" << '\n';
            return;
        }
        if (has_0) {
            for (int j = i; j < n; j += k) {
                s[j] = '0';
            }
        }
        if (has_1) {
            for (int j = i; j < n; j += k) {
                s[j] = '1';
            }
        }
    }

    vector<int> cnt(2);
    for (int i = 0; i < k; i++) {
        if (s[i] == '0') ++cnt[0];
        else if (s[i] == '1') ++cnt[1];
    }
    if (cnt[0] <= k / 2 && cnt[1] <= k / 2) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
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