void Get_next(char *s) {
    int j, L = strlen(s + 1);
    nxt[1] = j = 0;
    for(int i = 2; i <= L; i++) {
        while(j && s[i] != s[j + 1]) j = nxt[j] ;
        if(s[i] == s[j + 1]) j++;
        nxt[i] = j;
    }
}
int L1 = strlen(s1 + 1), L2 = strlen(s2 + 1) ;
for(int i = 1, j = 0; i <= L1; i++) {
    while(j > 0 && (j == L2 || s1[i] != s2[j + 1])) j = nxt[j] ;
    if(s1[i] == s2[j + 1]) j++;
    //if(j == L2) 此时位于末尾 
}
