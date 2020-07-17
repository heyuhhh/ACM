// Author : heyuhhh
// Created Time : 2020/07/14 11:41:23
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
const int N = 150000 + 5, M = 40000 + 5;

int n, m;
int a[N], b[M];

int p1[N], p2[N];

bitset<N> res, cur;

void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    iota(p1 + 1, p1 + n + 1, 1);
    iota(p2 + 1, p2 + m + 1, 1);
    sort(p1 + 1, p1 + n + 1, [&](int i, int j) {
        return a[i] > a[j];
    });
    sort(p2 + 1, p2 + m + 1, [&](int i, int j) {
        return b[i] > b[j];
    });
    res.set();
    for (int i = 1, p = 1; i <= m; i++) {
        while (p <= n && a[p1[p]] >= b[p2[i]]) {
            cur.set(p1[p]);
            ++p;
        }
        res &= (cur >> (p2[i] - 1));
    }
    int ans = res.count();
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}