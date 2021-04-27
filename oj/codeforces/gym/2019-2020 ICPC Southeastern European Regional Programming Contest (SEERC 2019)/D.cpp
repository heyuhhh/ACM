// Author : heyuhhh
// Created Time : 2020/10/05 16:04:23
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
    string s;
    cin >> s;
    int n = s.length();
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        ++cnt[s[i] - 'a'];
    }
    int Max = *max_element(all(cnt));
    if (Max <= n / 2) {
        sort(all(s));
        cout << "YES\n" << s << '\n';
        return; 
    }
    int f;
    int all = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == Max) {
            f = i;
        }
        if (cnt[i] > 0) ++all;
    }
    if (all == 1 || (all == 2 && cnt[f] >= n - 2)) {
        cout << "NO" << '\n';
        return;
    }
    string t = "";
    for (int i = 0; i < n / 2; i++) {
        t += ('a' + f);
        --cnt[f];
    }
    for (int i = 0; i < 26; i++) {
        if (i != f && cnt[i]) {
            --cnt[i];
            t += ('a' + i);
            break;
        }
    }
    while (cnt[f]) {
        t += ('a' + f);
        --cnt[f];
    }
    for (int i = 0; i < 26; i++) {
        while (cnt[i]--) {
            t += ('a' + i);
        }
    }
    cout << "YES\n" << t << '\n';
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