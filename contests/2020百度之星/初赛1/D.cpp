// Author : heyuhhh
// Created Time : 2020/07/19 14:42:00
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
void err(int x) {cerr << x;}
void err(long long x) {cerr << x;}
void err(double x) {cerr << x;}
void err(char x) {cerr << '"' << x << '"';}
void err(const string &x) {cerr << '"' << x << '"';}
void _print() {cerr << "]\n";}
template<typename T, typename V>
  void err(const pair<T, V> &x) {cerr << '{'; err(x.first); cerr << ','; err(x.second); cerr << '}';}
template<typename T>
  void err(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), err(i); cerr << "}";}
template <typename T, typename... V>
  void _print(T t, V... v) {err(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef Local
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
//head
const int N = 1e5 + 5;
void run() {
    int n, sx, sy;
    cin >> n >> sx >> sy;
    --sx, --sy;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    static int dx[] = {-2, -1, 0, 1, 2, -3, 3};
    static int dy[] = {-2, -1, 0, 1, 2, -3, 3};
    auto ok = [&] (int x, int y, int px, int py) {
        return x >= 0 && x < n && y >= 0 && y < n && abs(px - x) + abs(py - y) <= 3 && (x != px || y != py);
    };
    auto D = [&] (int ex, int ey) {
        int q = min(abs(sx - ex), abs(sy - ey));
        int p = max(abs(sx - ex), abs(sy - ey));
        int res = q + (p - q + 1) / 2;
        return res;
    };

    int ans = INF;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int dis = D(x, y);
            vector<int> p;
            for (int k1 = 0; k1 < 7; k1++) {
                for (int k2 = 0; k2 < 7; k2++) {
                    int nx = x + dx[k1], ny = y + dy[k2];
                    if (ok(nx, ny, x, y)) {
                        p.push_back(a[nx][ny]);
                    }
                }
            }
            sort(all(p));
            reverse(all(p));
            int t = min(sz(p), 7);
            vector<int> now;
            for (int i = 0; i < t; i++) {
                now.push_back(p[i]);
            }
            sort(all(now));
            reverse(all(now));

            int tot = 0;
            int res = dis;
            int sum = a[x][y];
            for (int i = 0; i < 8; i++) {
                int need = 8 * (i + 1) * (i + 1) - tot;
                if (need <= 0) continue;
                int turns = (need + sum - 1) / sum;
                tot += turns * sum;
                res += turns;
                if (i < sz(now)) {
                    sum += now[i];
                }
            }
            if (res < ans) {
                ans = res;
            }
        }
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
    int T; cin >> T; while(T--)
    run();
    return 0;
}