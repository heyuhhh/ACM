// Author : heyuhhh
// Created Time : 2020/09/26 16:38:53
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

int n;
string s, res;

void dfs(int cur) {
    if (cur == n) {
        while (!res.empty() && res.back() == '0') res.pop_back();
        cout << res << '\n';
        exit(0);
    }
    int now = s[cur] - '0';
    for (int i = (cur == 0); i < 10; i++) {
        res += char(i + '0');
        int x = 0;
        for (int j = 0; j <= cur; j++) {
            x = (x + (res[j] - '0') * (res[cur - j] - '0')) % 10;
        }
        if (x == now) dfs(cur + 1);
        res.pop_back();
    }
}

void run() {
    cin >> s;
    n = s.length();
    res = "";
    dfs(0);
    cout << -1 << '\n';
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