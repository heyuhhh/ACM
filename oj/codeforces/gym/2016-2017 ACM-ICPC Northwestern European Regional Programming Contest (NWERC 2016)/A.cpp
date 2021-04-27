// Author : heyuhhh
// Created Time : 2021/03/26 14:24:32
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
const int N = 41, M = 401, K = 82;

int n, m;
string s[N];
string dp[N][K];
int last[N][K];

inline string change(const string& last, string now, int cnt) {
    int tmp = cnt;
    string t = now;
    int pos = 0;
    while (pos < m && cnt) {
        if (now[pos] != last[pos]) {
            now[pos] = last[pos];
            --cnt;
        }
        ++pos;
    }
    if (now >= last) return now;
    --pos;
    while (pos >= 0 && now[pos] == '9') --pos;
    if (pos < 0) return "";
    cnt = tmp;
    now = t;
    for (int i = 0; i < pos; i++) {
        if (now[i] != last[i]) {
            now[i] = last[i];
            --cnt;
        }
    }
    if (now[pos] != last[pos] + 1) {
        now[pos] = (last[pos] + 1);
        --cnt;
    }
    for (int i = pos + 1; cnt && i < m; i++) {
        if (now[i] != '0') {
            now[i] = '0';
            --cnt;
        }
    }
    if (now >= last) return now;
    return "";
}

void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= m; i++) {
        dp[0][0] += "0";
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < K; j++) if (dp[i][j] != "") {
            for (int t = 0; t <= m && t + j < K; t++) {
                auto now = change(dp[i][j], s[i + 1], t);
                if (now != "" && dp[i][j] <= now) {
                    if (dp[i + 1][t + j] == "" || now < dp[i + 1][t + j]) {
                        dp[i + 1][t + j] = now;
                        last[i + 1][t + j] = j;
                    }
                }
            }
        }
    }

    int s = 0;
    for (s = 0; s < K; s++) {
        if (dp[n][s] != "") {
            break;
        }
    }
    vector<string> ans;

    int i = n;
    while (i) {
        ans.emplace_back(dp[i][s]);
        s = last[i][s];
        --i;
    }

    reverse(all(ans));
    for (auto& it : ans) {
        cout << it << '\n';
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