// Author : heyuhhh
// Created Time : 2020/09/06 10:35:55
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
    vector<ll> a(n + 1);
    vector<int> b(n + 1), in(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] != -1)
            ++in[b[i]];
    }
    queue<int> q;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            d[i] = 0;
        }
    }
    
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (b[x] != -1 && --in[b[x]] == 0) {
            d[b[x]] = d[x] + 1;
            q.push(b[x]);
        }
    }

    multiset<pair<int, int>> z;
    multiset<pair<int, int>, greater<pair<int, int>>> f;

    for (int i = 1; i <= n; i++) {
        if (a[i] >= 0) z.insert(MP(d[i], i));
        else f.insert(MP(d[i], i));
    }
    ll ans = 0;
    vector<int> p;
    while (!z.empty() || !f.empty()) {
        auto it = f.begin();
        if (!z.empty()) it = z.begin();
        int i = (it -> se);
        p.push_back(i);
        ans += a[i];
        if (!z.empty()) z.erase(it);
        else f.erase(it);
        if (b[i] != -1) {
            bool flag = false;
            if (a[b[i]] >= 0) {
                auto t = z.lower_bound(MP(d[b[i]], b[i]));
                if ((*t) == MP(d[b[i]], b[i]))
                    z.erase(t), flag = true;
            } else {
                auto t = f.lower_bound(MP(d[b[i]], b[i]));
                if ((*t) == MP(d[b[i]], b[i]))
                    f.erase(t), flag = true;
            }
            if (flag) {
                a[b[i]] += a[i];
                if (a[b[i]] >= 0) 
                    z.insert(MP(d[b[i]], b[i]));
                else 
                    f.insert(MP(d[b[i]], b[i]));
            }
        }
    }
    cout << ans << '\n';
    for (auto& it : p) {
        cout << it << ' ';
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
    run();
    return 0;
}