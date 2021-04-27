// Author : heyuhhh
// Created Time : 2020/12/04 15:42:12
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    while (k--) {
        string t = s + s;
        int len = t.length();
        string res = "";
        for (int i = 0; i < len; i += 2) {
            string p;
            if (t[i] == 'S') {
                if (t[i + 1] == 'P') res += "S";
                if (t[i + 1] == 'S') res += "S";
                if (t[i + 1] == 'R') res += "R";
            }
            if (t[i] == 'R') {
                if (t[i + 1] == 'P') res += "P";
                if (t[i + 1] == 'S') res += "R";
                if (t[i + 1] == 'R') res += "R";
            }
            if (t[i] == 'P') {
                if (t[i + 1] == 'P') res += "P";        
                if (t[i + 1] == 'S') res += "S";
                if (t[i + 1] == 'R') res += "P";
            }
        }
        s = res;
    }
    cout << s[0] << '\n';
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