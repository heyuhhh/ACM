// Author : heyuhhh
// Created Time : 2021/03/20 20:36:04
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
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    vector<vector<int>> mp(h, vector<int>(w));
    int ans = 0;
    function<void(int, int)> gao = [&] (int A, int B) {
        if (A < 0 || B < 0) return;
        if (A + B == 0) {
            ++ans;
            return;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) if (!mp[i][j]) {
                mp[i][j] = 1;
                gao(A, B - 1);
                mp[i][j] = 0;
                if (j + 1 < w && !mp[i][j + 1]) {
                    mp[i][j] = mp[i][j + 1] = 1;
                    gao(A - 1, B);
                    mp[i][j] = mp[i][j + 1] = 0;
                }
                if (i + 1 < h && !mp[i + 1][j]) {
                    mp[i][j] = mp[i + 1][j] = 1;
                    gao(A - 1, B);
                    mp[i][j] = mp[i + 1][j] = 0;
                }
                return;
            }
        }
    };
    gao(a, b);
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