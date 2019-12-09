struct Manacher{
    char ch[N << 1];
    int p[N << 1];
    void work(char *s) {
        int l = 0;
        ch[l++] = '&'; ch[l++] = '#';
        for(int i = 0; s[i]; i++) {
            ch[l++] = s[i];
            ch[l++] = '#';
        }
        ch[l] = '\0';
        int mx = 0, id = 0;
        for(int i = 0; i < l; i++) {
            p[i] = i < mx ? min(p[2 * id - i], mx - i) : 1;
            while(ch[i + p[i]] == ch[i - p[i]]) p[i]++;
            if(i + p[i] > mx) mx = i + p[i], id = i;
        }
    }
}Man;
