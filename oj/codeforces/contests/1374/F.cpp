// Author : heyuhhh
// Created Time : 2020/07/17 14:18:49
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    auto shift = [&] (int i) {
        int x = a[i], y = a[i + 1], z = a[i + 2];
        a[i + 1] = x;
        a[i + 2] = y;
        a[i] = z;
        ans.push_back(i);
    };
    for (int rb = n - 1; rb >= 2; rb--) {
        int Max = 0, p;
        for (int i = 0; i <= rb; i++) {
            if (a[i] > Max) {
                Max = a[i];
                p = i;
            }
        }
        // cout << rb << ' ' << Max << ' ' << p << '\n';
        while (p <= rb - 2) {
            shift(p++);
        }
        if (p == rb - 1) {
            shift(p - 1);
        }
    }
    if (a[1] < a[0]) {
        if (n == 3) {
            cout << -1 << '\n'; 
            return;
        } 
        if (a[2] != a[3]) {
            shift(0);
            shift(0);
            if (a[0] <= a[1] && a[1] <= a[2] && a[2] <= a[3]) {}
            else {
                cout << -1 << '\n';
                return;
            }
        } else {
            shift(1);
            shift(0);
        }
    }
    cout << sz(ans) << '\n';
    for (auto it : ans) {
        cout << it + 1 << ' ';
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