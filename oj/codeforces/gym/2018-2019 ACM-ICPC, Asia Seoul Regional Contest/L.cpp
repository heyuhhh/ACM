#include<bits/stdc++.h>
using namespace std;

struct par {
	int d, id;
	bool operator<(const par &f) const {
		return d < f.id;
	}
};
int flag;
int n, m, w, h;
priority_queue<par> q;
vector<int> ans[2010];
vector<par> qu[2010];
int day[2010];
int num;
int cnt[2010];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> w >> h;
	int f;
	for(int i = 1; i <= n; i++) {
		cin >> f;
		q.push((par){f, i});
	}
	for(int i = 1; i <= m; i++) {
	 	cin >> day[i];
	 	if(flag) continue;
	 	num -= cnt[i];
	 	for(auto it: qu[i]) q.push(it);
	 	while(num < day[i] && !q.empty()) {
			num++;
			par tmp = q.top();
			q.pop();
			tmp.d -= w;
			if(tmp.d) qu[i + w + h].push_back(tmp);
			cnt[i + w]++;
			ans[tmp.id].push_back(i);
		}
		if(num < day[i]) {
			cout << -1 << endl;
			flag = 1;
		}
	}
	if(flag) return 0;

	cout << "1" << endl;
	for(int i = 1; i <= n; i++) {
		for(auto it: ans[i]) cout << it << " ";
		cout << endl;
	}
}
