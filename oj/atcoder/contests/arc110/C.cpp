// Author : heyuhhh
// Created Time : 2020/12/05 20:34:52
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
    vector<int> p(n);
    vector<int> at(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        --p[i];
        at[p[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        if (p[i] == i) {
            cout << -1 << '\n';
            return;
        }
    }

    vector<bool> used(n);
    vector<int> ans;

    auto change = [&] (int x) {
        int y = x + 1;
        int p1 = p[x], p2 = p[y];
        swap(p[x], p[y]);
        swap(at[p1], at[p2]);
    };

    for (int i = n - 1; i >= 0; i--) {
        while (at[i] != i) {
            if (!used[at[i]]) {
                int pos = at[i];
                used[pos] = true;
                change(pos);
                ans.emplace_back(pos);
            } else {
                cout << -1 << '\n';
                return;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (!used[i]) {
            cout << -1 << '\n';
            return;
        }
    }
    for (auto it : ans) {
        cout << it + 1 << '\n';
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