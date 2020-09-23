// Author : heyuhhh
// Created Time : 2020/09/08 23:13:38
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
    if (n == 1) {
        cout << "! 1 1" << endl;
        return;
    }
    vector<int> p(n + 1);
    auto query = [&] (int x, int y) {
        cout << '?' << ' ' << x << ' ' << y << endl;
        int t;
        cin >> t;
        return t;
    };
    int last = 1;
    for (int i = 2; i <= n; i++) {
        int x = query(last, i), y = query(i, last);
        if (x > y) 
            p[last] = x, last = i;
        else 
            p[i] = y;
    }
    vector<bool> chk(n + 1);
    for (int i = 1; i <= n; i++)
        chk[p[i]] = true;
    for (int i = 1; i <= n; i++)
        if (!chk[i])
            p[last] = i;
    cout << "!";
    for (int i = 1; i <= n; i++)
        cout << " " << p[i];
    cout << endl;
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