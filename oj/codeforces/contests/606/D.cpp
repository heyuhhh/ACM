/*
 * Author:  heyuhhh
 * Created Time:  2019/12/14 19:48:43
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 2e5 + 5;

int n;
string s[N];
map <string, int> mp;
int cnt[2][2];
bool chk[N];

string rev(string &S) {
    reverse(S.begin(), S.end());
    return S;
}

void run(){
    cin >> n;
    mp.clear();
    for(int i = 1; i <= n; i++) chk[i] = 0;
    cnt[0][1] = cnt[1][0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        int len = s[i].length();
        if(len > 1) {
            if(s[i][0] != s[i][len - 1]) mp[s[i]] = i;
            if(s[i][0] == '0' && s[i][len - 1] == '1') ++cnt[0][1];
            else if(s[i][0] == '1' && s[i][len - 1] == '0')++cnt[1][0];
        }    
    }
    if(cnt[0][1] == 0 && cnt[1][0] == 0) {
        int cnt1 = 0, cnt2 = 0;
        for(int i = 1; i <= n; i++) {
            int len = s[i].length();
            if(s[i][0] == '0' && s[i][len - 1] == '0') ++cnt1;
            else ++cnt2;   
        }
        if(cnt1 && cnt2) cout << -1 << '\n';
        else cout << 0 << '\n' << '\n';
        return;   
    }
    int d = abs(cnt[0][1] - cnt[1][0]);
    int need = d / 2, ans;
    if(cnt[0][1] > cnt[1][0]) {
        for(int i = 1; i <= n && need; i++) {
            int len = s[i].length();
            if(len > 1 && s[i][0] == '0' && s[i][len - 1] == '1') {
                rev(s[i]);
                if(mp.find(s[i]) == mp.end()) {
                    --need; chk[i] = 1;  
                } 
                rev(s[i]);
            }   
        }
    } else {
        for(int i = 1; i <= n && need; i++) {
            int len = s[i].length();
            if(len > 1 && s[i][0] == '1' && s[i][len - 1] == '0') {
                rev(s[i]);
                if(mp.find(s[i]) == mp.end()) {
                    --need; chk[i] = 1;  
                } 
                rev(s[i]);
            }   
        }  
    }
    if(need == 0) ans = d / 2;   
    else {
        cout << -1 << '\n';
        return;   
    }
    cout << ans << '\n';
    for(int i = 1; i <= n; i++) if(chk[i]) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
