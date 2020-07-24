// Author : heyuhhh
// Created Time : 2020/07/20 09:41:10
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
const int N = 8e5 + 5;

int n, m;
int f[N];
list<int> lists[N];
vector<int> G[N];

void init() {
    for (int i = 0; i < n; i++) {
        f[i] = i;
        G[i].clear();
        lists[i].clear();
        lists[i].push_back(i);
    }
}

int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}

void Union(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        f[fy] = fx;
        lists[fx].splice(lists[fx].end(), lists[fy]);
    }
}

void run() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int q;
    cin >> q;
    while (q--) {
        int o;
        cin >> o;
        if (find(o) != o) continue;
        int size = sz(lists[o]);
        for (int i = 0; i < size; i++) {
            int u = lists[o].front();
            for (auto v : G[u]) {
                Union(o, v);
            }
            lists[o].pop_front();
        }
    }
    for (int i = 0; i < n; i++) {
        cout << find(i) << ' ';
    }
    cout << '\n';
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