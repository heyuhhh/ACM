// Author : heyuhhh
// Created Time : 2020/08/20 13:54:19
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

string pre[] = {
"....\n....\n....\n....\n",//-->0

"-1", 

"-1",

"X...\n....\n....\n....\n",//-->3

"-1",

".X..\n....\n....\n....\n",//-->5

"XX..\n....\n....\n....\n",//-->6

"XX..\nX...\n....\n....\n",//-->7

"X.X.\n....\n....\n....\n",//-->8

"XXX.\n....\n....\n....\n",//-->9

"XXXX\n....\n....\n....\n",//-->10

"X.X.\nX...\n....\n....\n",//-->11

"X.XX\nX...\n....\n....\n",//-->12

"XX.X\n.X..\n....\n....\n",//-->13

".X.X\n.X..\n....\n....\n",//-->14

".X.X\nXX..\n....\n....\n",//-->15

"..X.\nX.X.\n....\n....\n",//-->16

"X.X.\nX.X.\n....\n....\n",//-->17

"..X.\nXXX.\n....\n....\n",//-->18

"X...\nXXXX\n....\n....\n",//-->19

"....\nXXXX\n....\n....\n",//-->20

"X.X.\nX.XX\nX...\n....\n",//-->21

".X..\n.X.X\n.X..\n....\n",//-->22

".X.X\n.X.X\n.X..\n....\n",//-->23

".X.X\n.X.X\nXX..\n....\n",//-->24

"X.X.\n..X.\nX.X.\n....\n",//-->25

"X.X.\nX.X.\nX.X.\n....\n",//-->26

"XXXX\n....\nXXX.\n....\n",//-->27

"X.X.\n....\nXXXX\n....\n",//-->28

"XXX.\n....\nXXXX\n....\n",//-->29

"XXXX\n....\nXXXX\n....\n",//-->30

"X.X.X\n..X.X\nX.X..\n.....\n.....\n"
};

void run() {
    int s;
    cin >> s;
    if (s > 31) {
        int d = s % 8;
        int k = s / 8;
        vector<vector<int>> mp(25, vector<int>(25));
        int i, j;
        for (i = 1; i < 24 && k; i += 2) {
            for (j = 1; j < 24 && k; j += 2) {
                mp[i][j] = 1;
                --k;
            }
        }
        if (d == 0) {
        }
        if (d == 1) {
            mp[0][0] = 1;
        }
        if (d == 2) {
            mp[23][23] = 1;
            mp[1][2] = mp[1][4] = 1;
            mp[1][5] = mp[1][7] = 0;
        }
        if (d == 3) {
            mp[24][24] = 1; 
        }
        if (d == 4) {
            mp[0][0] = 1;
            mp[24][24] = 1;
        }
        if (d == 5) {
            mp[23][23] = mp[23][24] = 1;
            mp[1][2] = mp[1][4] = 1;
            mp[1][5] = mp[1][7] = 0;
        }
        if (d == 6) {
            mp[0][1] = 1;
            mp[24][24] = 1;
        }
        if (d == 7) {
            mp[23][23] = mp[24][24] = 1;
            mp[1][1] = 0; mp[1][2] = 1;
        }
        cout << 25 << ' ' << 25 << endl;
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 25; j++) {
                if (mp[i][j]) cout << "X";
                else cout << ".";
            }
            cout << '\n';
        }
    } else {
        if (s == 1) {
            cout << 1 << ' ' << 2 << '\n';
            cout << "X." << '\n';
        } else if (s == 2) {
            cout << 1 << ' ' << 3 << '\n';
            cout << ".X." << '\n';
        } else if (s == 4) {
            cout << 2 << ' ' << 2 << '\n';
            cout << "X.\nX." << '\n';
        } else if (s <= 30) {
            cout << 4 << ' ' << 4 << '\n';
            cout << pre[s];
        } else {
            cout << 5 << ' ' << 5 << '\n';
            cout << pre[s];
        }
    }
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