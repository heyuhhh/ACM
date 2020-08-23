// Author : heyuhhh
// Created Time : 2020/07/19 14:17:08
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
const int N = 1000 + 5;

int GCD[N][N], f[N][N];
void init() {
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            GCD[i][j] = __gcd(i, j);
        }
    }
    for (int i = 1; i < N; i++) {
        f[1][i] = f[i][1] = i;
    }
    for (int i = 2; i < N; i++) {
        for (int j = 2; j < N; j++) {
            f[i][j] = max(f[i][j - 1], f[i - 1][j]) + (GCD[i][j] == 1);
        }
    }
}

void run() {
    int a, b;
    cin >> a >> b;
    int ans = f[a][b];
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    int T; cin >> T; while(T--)
    run();
    return 0;
}