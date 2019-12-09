bool check(int k) {
    int y = 0, m = 0, d = 0;
    for(int i = 0; i < 4; i++) y = y * 10 + (a[s[k][i] - 'A']);
    for(int i = 5; i < 7; i++) m = m * 10 + (a[s[k][i] - 'A']);
    for(int i = 8; i < 10; i++) d = d * 10 + (a[s[k][i] - 'A']);
    if(y < 1600 || y > 9999 || m > 12 || d > 31) return false;
    if((m == 2 && d > 28 + (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)))) return false;
    if(m != 2 && d > days[m]) return false;
    if(m < 3) y--, m += 12;
    return (y + y / 4 - y / 100 + y / 400 + d + 1 + 2 * m + 3 * (m + 1) / 5) % 7 == 5; //年份大于1582
	return (y + y / 4 + 5 + 3 * (m + 1) / 5 + d + 2 * m) % 7 //年份小于1582 
}
