// Author : heyuhhh
// Created Time : 2021/03/27 20:49:51
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
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    --x, --y;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    int ans = 1;
    for (int j = y - 1; j >= 0; j--) {
        if (s[x][j] == '.') ++ans;
        else break;
    }
    for (int j = y + 1; j < w; j++) {
        if (s[x][j] == '.') ++ans;
        else break;
    }
    for (int i = x - 1; i >= 0; i--) {
        if (s[i][y] == '.') ++ans;
        else break;
    }
    for (int i = x + 1; i < h; i++) {
        if (s[i][y] == '.') ++ans;
        else break;
    }
    cout << ans << '\n';
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