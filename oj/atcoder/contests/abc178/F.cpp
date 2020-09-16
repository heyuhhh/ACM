// Author : heyuhhh
// Created Time : 2020/09/13 21:37:08
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
    vector<int> cntA(n), cntB(n);
    multiset<int> S;
    vector<vector<int>> G(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        ++cntA[a[i]];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        --b[i];
        ++cntB[b[i]];
    }
    for (int i = 0; i < n; i++) {
        if (cntA[i] + cntB[i] > n) {
            cout << "No" << '\n';
            return;
        }
    }
    reverse(all(b));
    int l = n, r = -1, c = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            l = i;
            c = a[i];
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == b[i]) {
            r = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != c && b[i] != c && l <= r) {
            swap(b[i], b[l]);
            ++l;
        }
    }
    cout << "Yes" << '\n';
    for (int i = 0; i < n; i++) {
        cout << b[i] + 1 << " \n"[i == n - 1];
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