// Author : heyuhhh
// Created Time : 2021/02/22 13:58:10
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
    int n, k;
    cin >> n >> k;
    vector<int> l(k), r(k);
    vector<ll> x(k);
    for (int i = 0; i < k; i++) {
        cin >> l[i] >> r[i] >> x[i];
        --l[i], --r[i];
    }
    vector<int> ok(k, 1);
    auto out = [&] (int op = 0) {
        for (int i = 0; i < k; i++) {
            cout << (op == 0 ? ok[i] : 1);
        }
        exit(0);
    };
    vector<vector<int>> can(60, vector<int>(k));
    auto solve = [&] (int bit) {
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            a[i] = (x[i] >> bit & 1);
        }
        vector<int> cnt(n + 1);
        vector<ll> id(n + 1);
        for (int i = 0; i < k; i++) if (a[i]) {
            ++cnt[l[i]], --cnt[r[i] + 1];
            id[l[i]] += i + 1;
            id[r[i] + 1] -= i + 1;
        }
        for (int i = 1; i <= n; i++) {
            cnt[i] += cnt[i - 1];
            id[i] += id[i - 1];
        }
        vector<ll> sum(n), cnt0(n);
        auto calc = [&] (int l, int r, int op = 0) {
            if (op == 0) {
                return l == 0 ? sum[r] : sum[r] - sum[l - 1];
            } else {
                return l == 0 ? cnt0[r] : cnt0[r] - cnt0[l - 1];
            }
        };
        for (int i = 0; i < n; i++) {
            if (cnt[i] >= 2) id[i] = -1;
            sum[i] = id[i];
            if (i) sum[i] += sum[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) ++cnt0[i];
        }
        for (int i = 1; i < n; i++) {
            cnt0[i] += cnt0[i - 1];
        }

        vector<int> good(k);
        int num0 = 0, tmp;
        int LL = -1, RR = INF;
        for (int i = 0; i < k; i++) if (a[i] == 0) {
            if (calc(l[i], r[i], 1) > 0) continue;
            ++num0;
            tmp = i;
            RR = min(RR, r[i]);
            LL = max(LL, l[i]);
        }
        if (num0 == 0) {
            for (int i = 0; i < k; i++) {
                good[i] = 1;
            }
            can[bit] = good;
            return;
        } else if (num0 == 1) {
            good[tmp] = 1;
        }
        
        for (int i = 0; i < k; i++) if (a[i] == 0) {
            if (calc(l[i], r[i]) == -(r[i] - l[i] + 1)) {
                can[bit] = good;
                return;
            }
        }

        vector<int> L(k + 1, -1), R(k + 1, -1);
        for (int i = 0; i < n; i++) if (id[i] > 0) {
            R[id[i]] = i;
        }
        for (int i = n - 1; i >= 0; i--) if (id[i] > 0) {
            L[id[i]] = i;
        }
        
        for (int i = 1; i <= k; i++) if (L[i] != -1) {
            if (L[i] <= RR && LL <= R[i]) {
                good[i - 1] = 1;
            }
        }
        can[bit] = good;
    };
    for (int i = 0; i < 60; i++) {
        solve(i);
    }
    // for (int j = 0; j < 2; j++) {
    //     for (int i = 0; i < k; i++) {
    //         cout << can[j][i] << ' ';
    //     } cout << endl;
    // }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 60; j++) {
            if (can[j][i] == 0) {
                ok[i] = 0;
            }
        }
    }
    out();
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