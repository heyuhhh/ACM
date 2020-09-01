// Author : heyuhhh
// Created Time : 2020/08/24 10:11:22
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
const int N = 1e6 + 5;

int n;
int to[N], len[N];

int find(int x, int L) {
    if (x >= n || len[x] >= L) return x;
    return to[x] = find(to[x], L);
}

void run() {
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        to[i] = i + 1;
    }
    int zero = n, one = n;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') len[i] = one - i, zero = i;
        if (s[i] == '1') len[i] = zero - i, one = i;
        if (s[i] == '?') len[i] = len[i + 1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        int res = 0;
        int cur = find(0, i);
        while (cur < n) {
            ++res;
            cur = find(cur + i, i);
        }
        cout << res << " \n"[i == n];
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