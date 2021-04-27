#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 33333333;

int primes[N], tot;
bool v[N];

void init() {
    for (int i = 2; i < N; i++) {
        if (!v[i]) {
            primes[++tot] = i;
        }
        for (int j = 1; j <= tot && primes[j] * i < N; j++) {
            v[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void run() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<ll> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<vector<pair<int, int>>> G(m);
    vector<ll> ans(m);
    for (int i = 0; i < k; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        --u, --v;
        G[u].emplace_back(v, d);
    }
    int j = 1;
    for (int i = 0; i < m; i++, j++) {
        int id = G[i][0].first;
        while (j <= tot && c[id] % primes[j]) ++j;
        if (j > tot) break;
        ans[i] = primes[j];
        for (auto v : G[i]) {
            while (c[v.first] % primes[j] == 0) {
                c[v.first] /= primes[j];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (ans[i] == 0) {
            ans[i] = c[G[i][0].first];
        }
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];
    }
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(10);
    // int T; cin >> T; while (T--) 
    init();
    run();
    return 0;
}