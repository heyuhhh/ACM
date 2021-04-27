#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
const int MAXN = 300007;
pii arr[MAXN];
int smx[MAXN], smi[MAXN];
int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	int n; cin >> n;
	int max2=0;
	for(int i=0; i<n; i++) {
		cin >> arr[i].first >> arr[i].second;
		max2=max(max2,arr[i].second * 2);
	}
	sort(arr, arr+n);
	smx[n] = 0, smi[n] = 0x3f3f3f3f;
	for(int i = n - 1; i >= 0;i--) smx[i] = max(smx[i + 1], arr[i].second * 2), smi[i] = min(smi[i + 1], arr[i].second * 2);
	smx[n] = 0, smi[n] = 0;
	int L = 0, R = max2;
	while(L<R) {
		int err2 = (R + L) / 2;
		int flag = 0;
		int i = 0;
		for(; i < n; i++) {
			if(arr[i].second * 2 > err2) {
				break;
			}
		}
		while(arr[i].first == arr[i - 1].first) i--;
		if(smx[i] - smi[i] <= err2) flag = 1;
		int mx = arr[i].second * 2, mi = arr[i].second * 2;
		for(i++; i <= n; i++) {
			if(arr[i].first != arr[i - 1].first && mx - mi <= err2 && smx[i] - smi[i] <= err2) {
				flag = 1;
				break;
			}
			mx = max(mx, arr[i].second * 2);
			mi = min(mi, arr[i].second * 2);
 		}
		
 		if(flag) R=err2;
		else L=err2 + 1;
	}
	cout << R / 2 << "." << ((R & 1) ? 5 : 0) << '\n';
}
