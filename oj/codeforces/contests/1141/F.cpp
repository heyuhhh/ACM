#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1505;
int n;
int a[N], sum[N], b[N*N];
vector <pii> g[N * N], T, res;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int D = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            b[++D] = sum[i] - sum[j - 1];
        }
    }
    sort(b + 1, b + D + 1);
    D = unique(b + 1, b + D + 1) - b;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            int p = lower_bound(b + 1, b + D + 1, sum[i] - sum[j - 1]) - b;
            g[p].emplace_back(mp(i, j));
        }
    }
    int l, ans = 0, p;
    for(int i = 0; i < N * N; i++) {
        if((int)g[i].size() != 0) {
            l = 0;
            T.clear();
            sort(g[i].begin(), g[i].end());
            int pre = -1;
            for(int j = 0; j < g[i].size(); j++) {
                if(g[i][j].second > pre) {
                    T.emplace_back(g[i][j]);
                    pre = g[i][j].first;
                }
            }
            if((int)T.size() > (int)res.size()) {
                swap(T, res);
            }
        }
    }
    cout << (int)res.size() << '\n';;
    for(int i = 0; i < res.size(); i++) {
        cout << res[i].second << " " << res[i].first << '\n';
    }
    return 0;
}
