// Author : heyuhhh
// Created Time : 2020/12/05 20:09:13
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
const ll MAX = 10000000000;
void run() {
    int n;
    cin >> n;
    string t;
    cin >> t;
    string s = "110";
    if (t.length() == 1) {
        if (t[0] == '0') {
            cout << MAX << '\n';
        } else {
            cout << 2ll * MAX << '\n';
        }
        return;
    }
    string tmp = "";
    int len = 0;
    while (len < n) {
        tmp += s;
        len += 3;
    }
    for (int i = 0; i < 10; i++) {
        if (tmp.find(t) != string::npos) {
            cout << MAX - len / 3 + 1 << '\n';
            return;
        }
        tmp += s;
        len += 3;
    }
    cout << 0 << '\n';
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