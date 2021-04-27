// Author : heyuhhh
// Created Time : 2021/03/01 13:38:00
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
    int lenS = s.length();
    vector<vector<int>> nxt(lenS + 1, vector<int>(26, lenS + 1));
    for (int i = lenS - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][s[i] - 'a'] = i + 1;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        int lenT = t.length();
        int p = 0;
        string res = "";
        for (int j = 0; j < lenT; j++) {
            if (nxt[p][t[j] - 'a'] <= lenS) {
                res += t[j];
                p = nxt[p][t[j] - 'a'];
            } else {
                break;
            }
        }
        if (res == "") {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            cout << res << '\n';
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