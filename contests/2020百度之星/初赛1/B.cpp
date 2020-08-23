// Author : heyuhhh
// Created Time : 2020/07/19 14:09:26
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

map <int, double> mp;
void init() {
    mp[95] = 4.3;
    mp[90] = 4;
    mp[85] = 3.7;
    mp[80] = 3.3;
    mp[75] = 3.0;
    mp[70] = 2.7;
    mp[67] = 2.3;
    mp[65] = 2.0;
    mp[62] = 1.7;
    mp[60] = 1.0;
    mp[0] = 0;
}

void run() {
    int x; 
    cin >> x;
    double ans = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        for (auto it2 = mp.begin(); it2 != mp.end(); ++it2) {
            for (auto it3 = mp.begin(); it3 != mp.end(); ++it3) {
                for (auto it4 = mp.begin(); it4 != mp.end(); ++it4) {
                    int scores = it->fi + it2->fi + it3->fi + it4->fi;
                    double res = it->se + it2->se + it3->se + it4->se;
                    if (scores <= x) {
                        ans = max(ans, res);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(1);
    init();
    int T; cin >> T; while(T--)
    run();
    return 0;
}