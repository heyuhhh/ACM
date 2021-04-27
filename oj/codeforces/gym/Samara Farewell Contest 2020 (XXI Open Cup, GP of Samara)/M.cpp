// Author : heyuhhh
// Created Time : 2021/03/10 11:01:16
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
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<bool> is(n);
    vector<int> mn(n), mx(n);
    vector<vector<int>> sons(n);
    function<void(int, int)> dfs = [&] (int u, int fa) {
        mn[u] = mx[u] = u;
        is[u] = false;
        bool flag = true;
        int has = 0;
        for (auto v : G[u]) if (v != fa) {
            dfs(v, u);
            mx[u] = max(mx[u], mx[v]);
            mn[u] = min(mn[u], mn[v]);
            sons[u].emplace_back(v);
            flag &= is[v];
            if (mn[v] > u) {
                if (has & 1) {
                    flag = false;
                }
                has |= 1;
            } else if (mx[v] < u) {
                if (has >> 1 & 1) {
                    flag = false;
                }
                has |= 2;
            } else {
                flag = false;
            }      
        }
        is[u] = flag;
    };
    dfs(0, -1);
    
    vector<int> ans;
    function<void(int, int, int, int, bool)> dfs2 = [&] (int u, int fa, int Min, int Max, bool from) {
        // cout << u << ' ' << Min << ' ' << Max << ' ' << from << '\n';
        if (sz(sons[u]) >= 4) return;
        if (sz(sons[u]) >= 3 && fa != -1) return;
        if (fa == -1) {
            if (is[u]) {
                ans.emplace_back(u);
            }
            for (auto v : sons[u]) {
                int has = 0;
                bool nfrom = from;
                int nMin = min(Min, u), nMax = max(Max, u);
                for (auto v2 : sons[u]) if (v2 != v) {
                    nfrom &= is[v2];
                    if (mn[v2] > u) {
                        if (has & 1) {
                            nfrom = false;
                        }
                        has |= 1;
                    } else if (mx[v2] < u) {
                        if (has >> 1 & 1) {
                            nfrom = false;
                        }
                        has |= 2;
                    } else {
                        nfrom = false;
                    }
                    nMin = min(nMin, mn[v2]);
                    nMax = max(nMax, mx[v2]);
                }
                if (nfrom) {
                    dfs2(v, u, nMin, nMax, nfrom);
                }
            }
        } else {
            int has = 0;
            if (Min > u) {
                has = 1;
            } else if (Max < u) {
                has = 2;
            }
            if (has == 0) return;
            if (sz(sons[u]) == 0) {
                ans.emplace_back(u);
            }
            if (sz(sons[u]) == 1) {
                bool flag = true;
                for (auto v : sons[u]) {
                    if (is[v]) {
                        if (mn[v] > u) {
                            if (has & 1) flag = false;
                            has |= 1;
                        } else if (mx[v] < u) {
                            if (has >> 1 & 1) flag = false;
                            has |= 2;
                        } else {
                            flag = false;
                        }
                    } else {
                        flag = false;
                    }
                }
                if (flag) {
                    ans.emplace_back(u);
                }
            }

            int t = has;
            // cout << t << '\n';
            for (auto v : sons[u]) {
                int has = t;
                bool nfrom = from;
                int nMin = min(Min, u), nMax = max(Max, u);
                for (auto v2 : sons[u]) if (v2 != v) {
                    nfrom &= is[v2];
                    if (mn[v2] > u) {
                        if (has & 1) {
                            nfrom = false;
                        }
                        has |= 1;
                    } else if (mx[v2] < u) {
                        if (has >> 1 & 1) {
                            nfrom = false;
                        }
                        has |= 2;
                    } else {
                        nfrom = false;
                    }
                    nMin = min(nMin, mn[v2]);
                    nMax = max(nMax, mx[v2]);
                }
                if (nfrom) {
                    dfs2(v, u, nMin, nMax, nfrom);
                }
            }            
        }
    };
    dfs2(0, -1, INF, -1, 1);
    if (sz(ans) == 0) {
        cout << -1 << '\n';
    } else {
        sort(all(ans));
        for (auto& it : ans) {
            cout << it + 1 << ' ';
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
    run();
    return 0;
}