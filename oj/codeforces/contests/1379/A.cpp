// Author : heyuhhh
// Created Time : 2020/07/19 17:04:42
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

const string str = "abacaba";

void run() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n - 6; i++) {
        if (s.substr(i, 7) == str) {
            ++cnt;
        }
    }
    if (cnt > 1) {
        cout << "NO" << '\n';
        return;
    }
    if (cnt == 1) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                s[i] = 'z';
            }
        }
        cout << "YES" << '\n';
        cout << s << '\n';
        return;
    }
    auto ok = [&] (int p) {
        for (int i = p; i < p + 7; i++) {
            if (s[i] == '?') continue;
            if (s[i] != str[i - p]) return false;
        }
        return true;
    };
    for (int i = 0; i < n - 6; i++) {
        if (ok(i)) {
            string t = s.substr(0, i) + str + s.substr(i + 7);
            for (int j = 0; j < n; j++) {
                if (t[j] == '?') {
                    t[j] = 'z';
                }
            }
            int ccnt = 0;
            for (int j = 0; j < n - 6; j++) {
                if (t.substr(j, 7) == str) {
                    ++ccnt;
                }
            }
            if (ccnt == 1) {
                cout << "YES" << '\n';
                cout << t << '\n';
                return;
            }
        }
    }
    cout << "NO" << '\n';
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