// Author : heyuhhh
// Created Time : 2020/09/14 23:29:47
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    sort(all(a));
    set<int> s;
    multiset<int> t;
    int last = -1;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int p = a[i];
        s.insert(p);
        if (last != -1) {
            t.insert(p - last);
            ans += p - last;
        }
        last = p;
    }
    cout << ans - (sz(t) > 0 ? *t.rbegin() : 0) << '\n';
    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op) {
            auto it = s.lower_bound(x);
            int prev = -1, succ = -1;
            if (it != s.end()) {
                succ = *it;
                t.insert(succ - x);
                ans += succ - x;
            }
            if (it != s.begin()) {
                --it;
                prev = *it;
                t.insert(x - prev);
                ans += x - prev;
            }
            s.insert(x);
            if (prev != -1 && succ != -1) {
                t.erase(t.lower_bound(succ - prev));
                ans -= succ - prev;
            }
        } else {
            auto it = s.upper_bound(x);
            int prev = -1, succ = -1;
            if (it != s.end()) {
                succ = *it;
                t.erase(t.lower_bound(succ - x));
                ans -= succ - x;
            }
            --it;
            if (it != s.begin()) {
                --it;
                prev = *it;
                t.erase(t.lower_bound(x - prev));
                ans -= x - prev;
            }
            s.erase(x);
            if (prev != -1 && succ != -1) {
                t.insert(succ - prev);
                ans += succ - prev;
            }
        }
        cout << ans - (sz(t) > 0 ? *t.rbegin() : 0) << '\n';
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