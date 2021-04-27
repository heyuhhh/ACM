#include <bits/stdc++.h>
using namespace std;


int r, s;
int rr, ss;
char a[10010];
int n, flag;
void run() {
    cin >> a + 1;
    n = strlen(a + 1);
    flag = 1;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 'Q') {
            if(s == 2) {
                cout << r << " - 2 (winner)\n";
            }
            else if(r == 2) {
                cout << "2 (winner) - " << s << '\n';
            }
            else {
                cout << r << " (" << rr ;
                if(flag == 1) cout << '*';           
                cout << ") - " << s << " (" << ss;
                if(flag == 2) cout << '*';
                cout << ")\n";
            }
            continue;
        }
        if(s == 2 || r == 2) continue;
        else if(a[i] == 'R') {
            if(flag == 1) ss++,flag = 2;
            else rr++, flag = 1;
        }
        else if(a[i] == 'S') {
            if(flag == 1) rr++,flag = 1;
            else ss++, flag = 2;
        }
        if(rr >= 5 && rr - ss >= 2) {
            r++;
            rr = ss = 0;
        }
        if(rr >= 10) {
            r++;
            rr = ss = 0;
        }
        if(ss >= 5 && ss - rr >= 2) {
            s++;
            rr = ss = 0;
        }
        if(ss == 10) {
            s++;
            rr = ss = 0;
        }
    }


}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    // int T; cin >> T; while (T--) 
    run();
    return 0;
}