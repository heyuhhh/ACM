// Author : heyuhhh
// Created Time : 2020/07/13 12:22:14
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
const int N = 2e5 + 5;

vector<int> G[N];
int n;
vector<int> v;
void dfs(int u, int fa) {
    int sons = 0;
    for (auto v : G[u]) {
        if (v != fa) {
            dfs(v, u);
            ++sons;
        }
    }
    if (sons == 0) {
        v.push_back(u);
    }
}

int d[N];

void run() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; 
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        ++d[u], ++d[v];
    }
    int rt = 1;
    for (int i = 1; i <= n; i++) {
        if (d[i] > 1) {
            rt = i;
        }
    }
    dfs(rt, 0);
    int len = sz(v);
    int t = (len + 1) / 2;
    vector<pii> ans;
    for (int i = 0; i + t < len; i++) {
        ans.push_back(MP(v[i], v[i + t]));
    }
    if (len & 1) {
        if (v[len / 2] != rt) {
            ans.push_back(MP(v[len / 2], rt));
        }
    }
    cout << sz(ans) << '\n';
    for (auto it : ans) {
        cout << it.fi << ' ' << it.se << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
/*
9
1 2
1 3
1 4
2 5
2 6
3 7
3 8
5 9
*/