// Author : heyuhhh
// Created Time : 2020/07/20 12:28:20
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
    int a, b, c, d;
    vector<int> v(4);
    cin >> a >> b >> c >> d;
    v[0] = a, v[1] = b, v[2] = c, v[3] = d;
    sort(all(v));
    if (v[3] != v[2]) {
        if (b == v[3] || c == v[3]) {
            cout << "AB//CD" << '\n';
        } else {
            cout << "AB//DC" << '\n';
        }
    } else {
        if (a == d && a == v[3]) {
            cout << "AB//DC" << '\n';
        } else {
            cout << "AB//CD" << '\n';
        }
    }
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