#include <bits/stdc++.h>
using namespace std;

void run() {
    string s;
    cin >> s;
    int n = s.length();
    int k;
    cin >> k;
    vector<vector<int>> nxt(n + 1, vector<int>(26, n + 1));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][s[i] - 'a'] = i + 1;
    }
    int p = 0;
    while (k--) {
        for (int i = 0; i < 26; i++) {
            int np = nxt[p][i];
            if (n - np >= k) {
                cout << char('a' + i);
                p = np;
                break;
            }
        }
    }
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    run();
    return 0;
}