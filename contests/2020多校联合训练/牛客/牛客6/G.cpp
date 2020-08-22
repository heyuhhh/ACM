// Author : heyuhhh
// Created Time : 2020/07/27 14:59:28
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
mt19937 rnd(time(NULL));
const int N = 1e5 + 5;
void run() {
    int n, k;
    cin >> n >> k;
    int MAX = 2 * (n + 1) * n;
    if (MAX % k != 0 || k == 1 || n == 1) {
        cout << -1 << '\n';
        return;
    }
    vector<vector<int>> a(n + 1, vector<int>(n));
    vector<vector<int>> b(n, vector<int>(n + 1));
    if (n * (n + 1) % k == 0) {
        int num = MAX / k, p = 1;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = p;
                if (--num == 0) {
                    ++p;
                    num = MAX / k;
                }
            }
        }
        for (int j = 0; j <= n; j++) {
            for (int i = 0; i < n; i++) {
                b[i][j] = p;
                if (--num == 0) {
                    ++p;
                    num = MAX / k;
                }
            }
        }
        // (0, 0) ()
        for (int i = 0; i < n; i++) {
            swap(a[i][i], b[i][i]);
        }
        swap(a[n][0], b[0][n]);
        swap(a[0][n - 1], b[n - 1][0]);
        for (int i = 0; i <= n; i++) {
            bool ok = true;
            for (int j = 1; j < n; j++) {
                if (a[i][j] != a[i][j - 1]) {
                    ok = false;
                }
            }
            assert(!ok);
        }
        for (int j = 0; j <= n; j++) {
            bool ok = true;
            for (int i = 1; i < n; i++) {
                if (b[i][j] != b[i - 1][j]) {
                    ok = false;
                }
            }
            assert(!ok);
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " \n"[j == n - 1];
            }
        }
        for (int j = 0; j <= n; j++) {
            for (int i = 0; i < n; i++) {
                cout << b[i][j] << " \n"[i == n - 1];
            }
        }
    } else {
        vector<int> cnt(k, MAX / k);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                int x = 1ll * (rnd() % k) * (rnd() % k) % k;
                while (cnt[x] == 0) {
                    x = 1ll * (rnd() % k) * (rnd() % k) % k;
                }
                --cnt[k];
                cout << x + 1;
                if (j < n - 1) cout << ' ';
                else cout << '\n';
            }
        }
        for (int j = 0; j <= n; j++) {
            for (int i = 0; i < n; i++) {
                int x = 1ll * (rnd() % k) * (rnd() % k) % k;
                while (cnt[x] == 0) {
                    x = 1ll * (rnd() % k) * (rnd() % k) % k;
                }
                --cnt[k];
                cout << x + 1;
                if (j < n - 1) cout << ' ';
                else cout << '\n';
            }
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
    int T; cin >> T; while(T--)
    run();
    return 0;
}