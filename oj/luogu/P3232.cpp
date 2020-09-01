// Author : heyuhhh
// Created Time : 2020/08/18 10:51:32
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
const int N = 500 + 5, M = 3e5 + 5;

double a[N][N], b[N];

// a: 系数矩阵 b: 常数列 x: 答案列
double x[N];
void Gauss(double a[][N], double* b, int n) {
    for (int i = 1; i <= n; i++) {
        int p = i;
        for (int k = i + 1; k <= n; k++) {
            if (fabs(a[k][i]) > fabs(a[p][i])) p = k;
        }
        if (i != p) {
            swap(a[i], a[p]), swap(b[i], b[p]);
        }
        for (int k = i + 1; k <= n; k++) {
            double d = a[k][i] / a[i][i];
            b[k] -= d * b[i];
            for (int j = 1; j <= n; j++) {
                a[k][j] -= d * a[i][j];
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) b[i] -= x[j] * a[i][j];
        x[i] = b[i] / a[i][i];
    }
}

int n, m;
struct Edge {
    int u, v;
} e[M];
int d[N];
void run() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[i] = Edge {u, v};
        ++d[u], ++d[v];
    }
    for (int i = 1; i < n; i++) {
        a[i][i] = 1;
    }
    b[1] = 1;
    for (int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v;
        if (u != n) a[v][u] -= 1.0 / d[u];
        if (v != n) a[u][v] -= 1.0 / d[v];
    }
    Gauss(a, b, n - 1);
    sort(e + 1, e + m + 1, [&](Edge A, Edge B) {
        return x[A.u] / d[A.u] + x[A.v] / d[A.v] > x[B.u] / d[B.u] + x[B.v] / d[B.v];
    });
    double ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += 1.0 * i * (x[e[i].u] / d[e[i].u] + x[e[i].v] / d[e[i].v]);
    }
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(3);
    run();
    return 0;
}