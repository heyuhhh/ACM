// Author : heyuhhh
// Created Time : 2020/07/17 09:27:57
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
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> b(n, vector<int>(m));
    static int dx[] = {-1, 1, 0, 0};
    static int dy[] = {0, 0, -1, 1};
    auto ok = [&] (int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (ok(x, y)) {
                    b[i][j]++;
                }
            }
            if (b[i][j] < a[i][j]) {
                flag = false;
            }
        }
    }
    if (flag) {
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << b[i][j] << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "NO" << '\n';
    }
}
int main() {
#ifdef Local
   freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}