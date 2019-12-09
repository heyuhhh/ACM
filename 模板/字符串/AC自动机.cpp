queue <int> q;
struct ACAM{
    int sz;
    int ch[N][MAX];
    int cnt[N], fail[N];
    void init() {
        sz = -1;
        newnode();
    }
    int newnode() {
        memset(ch[++sz], 0, sizeof(ch[sz]));
        cnt[sz] = fail[sz] = 0;
        return sz;
    }
    void insert(char *s) {
        int u = 0;
        for(int i = 1; s[i]; i++) {
            int idx = s[i] - 'a';
            if(!ch[u][idx]) ch[u][idx] = newnode();
            u = ch[u][idx];
        }
        cnt[u]++;
    }
    void build() {
        while(!q.empty()) q.pop();
        for(int i = 0; i < 26; i++) {
            if(ch[0][i]) q.push(ch[0][i]);
        }
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int i = 0; i < 26; i++) {
                if(ch[cur][i]) {
                    fail[ch[cur][i]] = ch[fail[cur]][i];
                    q.push(ch[cur][i]);
                } else {
                    ch[cur][i] = ch[fail[cur]][i];
                }
            }
        }
    }
}ac;
