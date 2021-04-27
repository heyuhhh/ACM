// Author : heyuhhh
// Created Time : 2021/03/26 16:08:05
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = INF;
    vector<string> res;
    vector<string> t(n);
    t[0] = s[0];

    auto change = [&] (string& A, string B) {
        int res = 0;
        for (int i = 0; i < m; i++) {
            if (B[i] > A[i]) {
                return MP(res, B);
            } else if (B[i] == A[i]) {
                if (B[i] < '9') {
                    ++B[i];
                    return MP(res + 1, B);
                }
            } else {
                if (A[i] < '9') {
                    B[i] = A[i] + 1;
                    return MP(res + 1, B);
                } else {
                    B[i] = A[i];
                    ++res;
                }
            }
        }
        return MP(res, B);
    };

    int cnt = 0;
    for (int j = 0; j <= m; j++) {
        int num = cnt;
        for (int i = 1; i < n; i++) {
            auto cur = change(t[i - 1], s[i]);
            num += cur.fi;
            t[i] = cur.se;
        }
        if (num < ans) {
            ans = num;
            res = t;
        }
        if (j < m && s[0][j] != '0') {
            ++cnt;
            for (int k = 0; k <= j; k++) {
                t[0][k] = '0';
            }
            for (int k = j + 1; k < m; k++) {
                t[0][k] = s[0][k];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << t[i] << '\n';
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