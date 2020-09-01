// Author : heyuhhh
// Created Time : 2020/08/21 09:31:03
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
const int N = 2e5 + 5;
void run() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(10), num(N);
    auto add = [&] (int x, int v) {
        num[x] += v;
        if (v == 1) {
            if (num[x] == 2) ++cnt[2];
            else if (num[x] == 4) {
                --cnt[2]; ++cnt[4];
            } else if (num[x] == 6) {
                --cnt[4]; ++cnt[6];
            } else if (num[x] == 8) {
                --cnt[6]; ++cnt[8];
            }
        } else {
            if (num[x] == 7) {
                --cnt[8]; ++cnt[6];
            } else if (num[x] == 5) {
                --cnt[6]; ++cnt[4];
            } else if (num[x] == 3) {
                --cnt[4]; ++cnt[2];
            } else if (num[x] == 1) {
                --cnt[2];
            }
        }
    };
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        add(a[i], 1);
    }
    cin >> q;
    while (q--) {
        char op;
        cin >> op;
        int x;
        cin >> x;
        if (op == '-') {
            add(x, -1);
        } else {
            add(x, 1);
        }
        if ((cnt[2] && cnt[6]) || (cnt[4] && cnt[2] >= 2) || cnt[4] >= 2 || cnt[8]) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
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