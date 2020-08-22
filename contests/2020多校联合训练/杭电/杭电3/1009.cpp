// Author : heyuhhh
// Created Time : 2020/07/28 14:04:45
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
    int n = s.length();
    int sum = 0;
    int Min = n + 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') --sum;
        if (s[i] == '(') ++sum;
        Min = min(Min, sum);
    }
    if (Min < 0) {
        for (int i = 0; i < n && Min < 0; i++) {
            if (s[i] == '*') {
                s[i] = '(';
                ++Min;
            }
        }
    }
    if (Min < 0) {
        cout << "No solution!" << '\n';
        return;
    }
    
    sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') --sum;
        if (s[i] == '(') ++sum;
    }
    for (int i = n - 1; i >= 0 && sum > 0; i--) {
        if (s[i] == '*') {
            s[i] = ')';
            --sum;
        }
    }
    sum = 0;
    Min = n + 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') --sum;
        if (s[i] == '(') ++sum;
        Min = min(Min, sum);
    }
    if (sum != 0 || Min < 0) {
        cout << "No solution!" << '\n';
        return;
    }
    string res = "";
    for (int i = 0; i < n; i++) {
        if (s[i] != '*') res += s[i];
    }
    cout << res << '\n';
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