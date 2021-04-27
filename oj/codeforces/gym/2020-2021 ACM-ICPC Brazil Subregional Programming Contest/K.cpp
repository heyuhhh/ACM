#include <bits/stdc++.h>
using namespace std;
int p, f;
int fa[110], sz[110];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void run() {
    cin >> p >> f;
    for(int i = 1; i <= p; i++) fa[i] = i, sz[i] = 1;
    int x, y;
    for(int i = 1; i <= f; i++) {
        cin >> x >> y;
        x = find(x);
        y = find(y);
        if(x != y) fa[y] = x, sz[x] += sz[y];
    }
    for(int i = 1; i <= p; i++) if(i == find(i)) {
        if(sz[i] & 1) {
            cout << "N\n";
            return;
        }
    }
    cout << "Y\n";
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    // int T; cin >> T; while (T--) 
    run();
    return 0;
}