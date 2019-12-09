#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
unordered_map <int, LL> f, g;
LL inf = 0x3f3f3f3f3f3f3f3f;
LL calf(int x, int a, int b){
    if (x == 0) return 0;
    if (f.find(x) != f.end()) return f[x];
    int l = 0, r = x;
    while(l < r){
        int m = (l + r + 1) >> 1;
        //cout << m << endl;
        if (calf(m - 1, a, b) + b > calf(x - m, a, b) + a) r = m - 1;
        else l = m;
    }
    int m = l;
    LL tmp = inf;
    for (int i = max(m - 1, 1); i <= min(x, m + 1); i++)
        tmp = min(tmp, max(calf(i - 1, a, b) + b, calf(x - i, a, b) + a));
    f[x] = tmp;
    return tmp;
}
LL calg(int x, int a, int b){
    if (x == 0) return a;
    if (g.find(x) != g.end()) return g[x];
    int l = 0, r = x;
    while(l < r){
        int m = (l + r + 1) >> 1;
        if (calg(m - 1, a, b) + b > calf(x - m, a, b) + a) r = m - 1;
        else l = m;
    }
    int m = l;
    LL tmp = inf;
    for (int i = max(m - 1, 1); i <= min(x, m + 1); i++)
        tmp = min(tmp, max(calg(i - 1, a, b) + b, calf(x - i, a, b) + a));
    g[x] = tmp;
    return tmp;
}
int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        f.clear(), g.clear();
        if (l == 0) cout << calf(r, a, b) << endl;
        else cout << calg(r - l, a, b) << endl;
    }
    return 0;
}