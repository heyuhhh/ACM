// Author : heyuhhh
// Created Time : 2021/01/10 20:04:11
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
    vector<int> a(1 << n);
    for (int i = 0; i < 1 << n; i++) {
        cin >> a[i];
    }
    vector<int> c = a;
    for (int i = 0; i < 1 << n; i++) a[i] = i;
    while (sz(a) > 2) {
        vector<int> b;
        for (int i = 0; i < sz(a); i += 2) {
            if (c[a[i]] > c[a[i + 1]]) b.emplace_back(a[i]);
            else b.emplace_back(a[i + 1]);
        }
        swap(a, b);
    }
    if (c[a[0]] > c[a[1]]) {
        cout << a[1] + 1 << '\n';
    } else {
        cout << a[0] + 1 << '\n';
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