// Author : heyuhhh
// Created Time : 2020/07/21 10:14:10
#include <bits/stdc++.h>
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
// head
const int N = 1e5 + 5, M = 10;

struct SAM {
    const static int MAXNODE = N * M * 2;
    const static int M = 10;  //
    int go[MAXNODE][M], link[MAXNODE], len[MAXNODE];
    int last, sz, root;

    int newnode() {
        ++sz;
        memset(go[sz], 0, sizeof(go[sz]));
        return sz;
    }

    void init() {
        sz = 0;
        root = last = newnode();
        len[root] = link[root] = 0;
    }

    int split(int p, int q, int ch) {
        int clone = newnode();
        memcpy(go[clone], go[q], sizeof(go[q]));
        link[clone] = link[q];
        link[q] = clone;
        len[clone] = len[p] + 1;
        for (int i = p; i && go[i][ch] == q; i = link[i]) {
            go[i][ch] = clone;
        }
        return clone;
    }

    void insert(int ch) {
        if (go[last][ch]) {
            int q = go[last][ch];
            last = len[last] + 1 == len[q] ? q : split(last, q, ch);
            return;
        }
        // ----
        int cur = newnode();
        len[cur] = len[last] + 1;
        int p = last;
        for (; p && !go[p][ch]; p = link[p]) {
            go[p][ch] = cur;
        }
        if (!p) {
            link[cur] = root;
        } else {
            int q = go[p][ch];
            link[cur] = len[p] + 1 == len[q] ? q : split(p, q, ch);
        }
        last = cur;
    }

    ll solve() {
        ll ans = 0;
        for (int i = root + 1; i <= sz; ++i) {
           ans += len[i] - len[link[i]];
        }
        return ans;
    }
}sam;
int sam_id[N * M];
struct Trie {
    int ch[N * M][M];
    int root, cnt, last;

    int newnode() {
        memset(ch[++cnt], 0, sizeof(ch[cnt]));
        return cnt;
    }

    void init() {
        cnt = 0;
        root = newnode();
    }

    int insert(int last, int x) {
        if (!ch[last][x]) {
            ch[last][x] = newnode();
        }
        return ch[last][x];
    }

    void bfs() {
        int p = root;
        sam.init();
        sam_id[root] = sam.root;
        queue <int> q;
        q.push(p);
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (int i = 0; i < M; i++) {
                if (ch[u][i]) {
                    sam.last = sam_id[u];
                    sam.insert(i);
                    sam_id[ch[u][i]] = sam.last;
                    q.push(ch[u][i]);
                }
            }
        }
    }
}trie;

string s;
int n;
bool valid[N][M];
int trie_id[N][M];

void run() {
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        valid[i][s[i] - 'a'] = true;
        if (i > 0) {
            for (int j = 0; j < 10; j++) {
                if (valid[i - 1][j]) {
                    valid[i][max(j, s[i] - 'a')] = true;
                }
            }
        }
    }
    trie.init();
    for (int i = 0; i < 10; i++) {
        if (valid[n - 1][i]) {
            trie_id[n - 1][i] = trie.insert(trie.root, i);
        }
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < 10; j++) {
            if (valid[i - 1][j]) {
                for (int k = 0; k < 10; k++) {
                    if (valid[i][k] && max(j, s[i] - 'a') == k) {
                        trie_id[i - 1][j] = trie.insert(trie_id[i][k], j);
                    }
                }
            }
        }
    }
    trie.bfs();
    ll ans = sam.solve();
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}