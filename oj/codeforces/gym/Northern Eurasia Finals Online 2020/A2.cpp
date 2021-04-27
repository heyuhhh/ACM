// Author : heyuhhh
// Created Time : 2021/02/27 10:01:21
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
    int A, B;
    cin >> A >> B;
    int n = A + B;
    vector<int> v(n + 1), ls(n + 1), rs(n + 1);
    int tot = 1;
    function<void(int&, int)> solve = [&] (int& o, int s) {
        if (s == 0) return;
        o = tot++;
        // cout << o << ' ' << s << endl;
        if (s == 1) {
            if (A) {
                v[o] = 1;
                --A;
                return;
            }
            cout << -1 << '\n';
            exit(0);
        }
        if (B) {
            v[o] = 2;
            --B;
            s -= 2;
            solve(ls[o], s / 2);
            solve(rs[o], s - s / 2);
        } else if (A) {
            v[o] = 1;
            --A;
            s -= 1;
            solve(ls[o], s / 2);
            solve(rs[o], s - s / 2);
        } else {
            cout << -1 << '\n';
            exit(0);
        }
    };
    int t;
    solve(t, A + 2 * B);
    for (int i = 1; i <= n; i++) {
        cout << v[i] << ' ' << ls[i] << ' ' << rs[i] << '\n';
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