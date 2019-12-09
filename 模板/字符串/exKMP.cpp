struct ExKmp{
    int Next[N];
    int extend[N];
    void get_next(char *s) {
        int len = strlen(s + 1), p = 1, pos;
        Next[1] = len;
        while(p + 1 <= len && s[p] == s[p + 1]) p++;
        Next[pos = 2] = p - 1;
        for(int i = 3; i <= len; i++) {
            int l = Next[i - pos + 1];
            if(i + l < p + 1) Next[i] = l;
            else {
                int j = max(p - i + 1, 0);
                while(i + j <= len && s[j + 1] == s[i + j]) ++j;
                p = i + (Next[pos = i] = j) - 1;
            }
        }
    }
    void work(char *s, char *t) {
        get_next(t);
        int lens = strlen(s + 1), lent = strlen(t + 1), p = 1, pos;
        while(p <= lent && s[p] == t[p]) ++p;
        p = extend[pos = 1] = p - 1;
        for(int i = 2; i <= lens; i++) {
            int len = Next[i - pos + 1];
            if(len + i < p + 1) extend[i] = len;
            else {
                int j = max(p - i + 1, 0);
                while(i + j <= lens && j <= lent && t[j + 1] == s[i + j]) j++;
                p = i + (extend[pos = i] = j) - 1;
            }
        }
    }
}exkmp;
