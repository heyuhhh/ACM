// Author : heyuhhh
// Created Time : 2020/08/15 20:34:00
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
const int N = 1e7 + 5;

int _;

int ch[N][2], fa[N], tot;
ll sum[N], ed[N];

int newnode() {
    ++tot;
    ch[tot][0] = ch[tot][1] = sum[tot] = ed[tot] = fa[tot] = 0;
    return tot;
}

int ins(const string& s, int v) {
    int n = s.length();
    int rt = 0;
    for (int i = 0; i < n; i++) {
        if (ch[rt][s[i] - '0'] == 0) {
            ch[rt][s[i] - '0'] = newnode();
        }
        fa[ch[rt][s[i] - '0']] = rt;
        rt = ch[rt][s[i] - '0'];
        sum[rt] += v;
    }
    ed[rt] += v;
    return rt;
}

void del(const string& s) {
    int n = s.length();
    int rt = 0;
    for (int i = 0; i < n; i++) {
        rt = ch[rt][s[i] - '0'];
        if (rt == 0) {
            cout << "Not Exist" << '\n';
            return;
        }
    }
    ll v = ed[rt];
    // 是否存在这个子串
    if (v == 0) {
        cout << "Not Exist" << '\n';
        return;
    }
    ed[rt] = 0;
    while (rt) sum[rt] -= v, rt = fa[rt];
}

ll find(const string& s) {
    int n = s.length();
    int rt = 0;
    for (int i = 0; i < n; i++) {
        rt = ch[rt][s[i] - '0'];
        if (rt == 0) return 0;
    }
    return sum[rt];
}

void dfs(int x, int y) {
    sum[y] += sum[x];
    ed[y] += ed[x];

    if (ch[x][0] && ch[y][0]) {
        dfs(ch[x][0], ch[y][0]);
    } else if (ch[x][0]) {
        fa[ch[y][0] = ch[x][0]] = y;
    }

    if (ch[x][1] && ch[y][1]) {
        dfs(ch[x][1], ch[y][1]);
    } else if (ch[x][1]) {
        fa[ch[y][1] = ch[x][1]] = y;
    }
}

void merge(const string& s, const string& t) {
    int n = s.length(), m = t.length();
    int rt = 0;
    for (int i = 0; i < n; i++) {
        rt = ch[rt][s[i] - '0'];
        if (rt == 0) {
            cout << "Not Exist" << '\n';
            return;
        }
    }
    // 注意判断
    if (sum[rt] == 0) {
        cout << "Not Exist" << '\n';
        return;
    }
    int x = rt;
    ll v = sum[rt];
    // 删除
    rt = fa[rt];
    while (rt) sum[rt] -= v, rt = fa[rt];
    ch[fa[x]][s.back() - '0'] = 0;
    
    // 插入
    rt = 0;
    for (int i = 0; i < m; i++) {
        if (ch[rt][t[i] - '0'] == 0) {
            ch[rt][t[i] - '0'] = newnode();
        }
        fa[ch[rt][t[i] - '0']] = rt;
        rt = ch[rt][t[i] - '0'];
        sum[rt] += v;
    }

    // 最后一个点要去掉
    sum[rt] -= v;
    int y = rt;
    // 合并
    dfs(x, y);
}

void run() {
    ++_;
    cout << "Case " << _ << endl;
    tot = -1; newnode();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string op, s;
        cin >> op >> s;
        if (op == "I") {
            int v; cin >> v;
            ins(s, v);
        } else if (op == "D") {
            del(s);
        } else if (op == "Q") {
            ll res = find(s);
            cout << res << '\n';
        } else {
            string t;
            cin >> t;
            merge(s, t);
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