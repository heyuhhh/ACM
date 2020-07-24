// Author : heyuhhh
// Created Time : 2020/07/18 12:01:57
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
    string s;
    cin >> s;
    if (s.length() < 6) {
        cout << "ugly" << '\n';
        return;
    }
    for (int i = 0; i < 6; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    string t = s.substr(0, 6);
    if (t == "lovely") {
        cout << "lovely" << '\n';
    } else {
        cout << "ugly" << '\n';
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