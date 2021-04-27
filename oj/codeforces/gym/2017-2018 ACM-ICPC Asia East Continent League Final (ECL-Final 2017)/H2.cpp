#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[1000010];
int x, y, n;
bool flag;
pair<int, int> a[1000010]; 
void run() {
	cin >> s;
	cin >> x >> y;
	n = 0;
	a[0].first = -1;
	int cnt;
	for (int i = 0; s[i] != 0; i++) {
		if(s[i] == '?') cnt = 2;
		else if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') cnt = 1;
		else cnt = 0;
		if(cnt != a[n].first) {
			a[++n].first = cnt;
			a[n].second = 0;
		}
		a[n].second++;
	}
	cnt = 0;
	flag = 0;
	if(x == 1) {
		for (int i = 1; i <= n; i++) {
			cnt += a[i].second;
			if(a[i].first == 1 || cnt >= y) {
				cout << "DISLIKE" << endl;
				return;
			}
			if(a[i].first == 2) flag = 1;
		}
		if(flag) cout << "SURPRISE" << endl;
		else cout << "LIKE" << endl;
		return;
	}
	if(y == 1) {
		for (int i = 1; i <= n; i++) {
			cnt += a[i].second;
			if(a[i].first == 0 || cnt >= x) {
				cout << "DISLIKE" << endl;
				return;
			}
			if(a[i].first == 2) flag = 1;
		}
		if(flag) cout << "SURPRISE" << endl;
		else cout << "LIKE" << endl;
		return;
	}
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].first << ' ' << a[i].second << endl;
    // }
	for (int i = 1; i <= n; i++) {
		if(a[i].first) cnt += a[i].second;
		else cnt = 0;
		if(cnt >= x) flag = 1;
	}
	if(!flag) {
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if(a[i].first != 1) cnt += a[i].second;
			else cnt = 0;
			if(cnt >= y) flag = 1;
		}
	}
	if(!flag) {
		cout << "LIKE" << endl;
		return;
	}


    vector<int> pre(2);
    vector<int> bd(2);
    bd[0] = y, bd[1] = x;
    for (int i = 1; i <= n; i++) {
        int type = a[i].first, num = a[i].second;
        if (type < 2) {
            pre[type] += num;
            if (pre[type] >= bd[type]) {
                cout << "DISLIKE" << '\n';
                return;
            }
            pre[type ^ 1] = 0;
        } else {
            if (i == 1 || i == n) {
                continue;
            }
            if (num == 1) {
                if (a[i - 1].first != a[i + 1].first) {
                    pre[a[i + 1].first] = (pre[a[i - 1].first] + 1 >= bd[a[i - 1].first]);
                    pre[a[i - 1].first] = 0;
                } else {
                    pre[0] = pre[1] = 0;
                }
            } else {
                // 0   10101   1
                if (a[i - 1].first != a[i + 1].first) {
                    if (pre[a[i - 1].first] + 1 >= bd[a[i - 1].first]) {
                        if (a[i].second & 1) {
                            if (bd[a[i + 1].first] == 2) {
                                cout << "DISLIKE" << '\n';
                                return;
                            } else {
                                pre[0] = pre[1] = 0;
                            }
                        } else {
                            pre[0] = pre[1] = 0;
                        }
                    } else {
                        pre[0] = pre[1] = 0;
                    }
                } else {
                    // 0   1010   0
                    if (pre[a[i - 1].first] + 1 >= bd[a[i - 1].first]) {
                        if (a[i].second % 2 == 0) {
                            if (bd[0] == 2 && bd[1] == 2) {
                                cout << "DISLIKE" << '\n';
                                return;
                            }
                            pre[0] = pre[1] = 0;
                        } else {
                            pre[0] = pre[1] = 0;
                        }
                    } else {
                        pre[0] = pre[1] = 0;
                    }
                }
            }
        }
    }
    cout << "SURPRISE" << '\n';
}

int main() {
#ifdef Local
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >>T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		run();
	}
	return 0;
}

