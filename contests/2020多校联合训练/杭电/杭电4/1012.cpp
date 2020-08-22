// Author : heyuhhh
// Created Time : 2020/07/30 20:05:17
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
const int N = 5000 + 5;
int mp[N][N];
void run() {
    int n;
    cin >> n;
    vector<pair<pii, int>> ans;
    function <void(int, int, int)> draw = [&] (int x, int y, int n) {
        if (mp[x][y] == n) return;
        if (n <= 0) return;
        if (n == 1) {
            ans.emplace_back(MP(MP(x, y), 1));
            mp[x][y] = 1;
            return;
        }
        draw(x, y + 1, n - 1);
        draw(x - 1, y, n - 2);
        draw(x + 1, y, n - 3);
        draw(x, y - 1, n - 4);
        ans.emplace_back(MP(MP(x, y), n));
        mp[x][y] = n;
        return;
    };
    draw(2000, 2000, n);
    for (auto it : ans) {
        // cout << it.fi.fi << ' ' << it.fi.se << ' ' << it.se << '\n';
    }
    cout << sz(ans) << '\n';
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