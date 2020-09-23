#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)

// 0 down, 1 right, 2 up, 3 left

void fail() {
	cout << "impossible" << endl;
	exit(0);
}

int main() {
	int n; cin >> n;
	vector<array<int,4>> a(n);
	vector<int> xor_map(2*n+5);

	auto rot_piece = [&](int i) {
		rotate(begin(a[i]),begin(a[i])+1,end(a[i]));
	};
	
	FOR(i,0,n) FOR(j,0,4) {
		cin >> a[i][j];
		xor_map[a[i][j]] ^= i;
	}
	
	auto get = [&](int i, int dir) {
		int j = i ^ xor_map[a[i][dir]];
		while (a[j][dir^2] != a[i][dir]) rot_piece(j);
		return j;
	};

	int corner = -1;
	FOR(i,0,n) FOR(j,0,4) {
		if (a[i][2] == 0 && a[i][3] == 0) {
			corner = i;
			break;
		}
		rot_piece(i);
	}
	
	if (corner == -1) fail();
	
	vector<bool> used(n);
	vector<vector<int>> res;
	
	int cur = corner;
	while (true) {
		if (used[cur]) fail();
		res.push_back({cur});
		used[cur] = true;
		if (a[cur][0] == 0) break;
		
		if (a[cur][3] > 0) fail();
		cur = get(cur,0);
	}
	
	int h = res.size();
	
	while (a[res[0].back()][1] > 0) {
		FOR(i,0,h) {
			int lft = res[i].back();
			if (a[lft][1] == 0) fail();
			
			int rht = get(lft,1);
			if (used[rht]) fail();
			res[i].push_back(rht);
			used[rht] = true;
			
			if (i == 0 && a[rht][2] > 0) fail();
			if (i == h-1 && a[rht][0] > 0) fail();
			
			if (i > 0 && (a[rht][2] == 0 || a[rht][2] != a[res[i-1].back()][0])) fail();
		}
	}
	
	FOR(i,0,h) if (a[res[i].back()][1] > 0) fail();
	
	FOR(i,0,n) if (!used[i]) fail();
	
	cout << h << " " << res[0].size() << endl;
	
	for (auto row: res) {
		for (int x: row) cout << x+1 << " ";
		cout << endl;
	}
}
