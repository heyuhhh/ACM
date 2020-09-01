// Author : heyuhhh
// Created Time : 2020/07/17 13:46:58
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
    int n, m, k; 
    cin >> n >> m >> k;
    vector<pii> a, b, c;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t >> x[i] >> y[i];
        if (x[i] * y[i] == 1) {
            a.push_back(MP(t, 1));
        } else if (x[i]) {
            b.push_back(MP(t, i));
        } else if (y[i]) {
            c.push_back(MP(t, i));
        }
    }
    sort(all(b));
    sort(all(c));
    vector<bool> cx(n), cy(n);
    for (int i = 0; i < min(sz(b), sz(c)); i++) {
        int t = b[i].fi + c[i].fi;
        a.push_back(MP(t, 2));
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