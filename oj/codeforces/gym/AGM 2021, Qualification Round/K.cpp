#include<iostream>
using namespace std;
typedef unsigned long long ULL;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q; cin >> q;
	while(0<q--) {
		ULL n, x, y; cin >> n >> x >> y;
		for(ULL ox=x, oy=y; ; ox=x, oy=y) {
			int c[]={__builtin_ctz(x), __builtin_ctz(y)};
			if(c[0]<c[1]) {
				x+=x&-x;
			} else if(c[0]>c[1]) {
				y+=y&-y;
			} else {
				x+=x&-x;
				y+=y&-y;
			}
			if(x+y>n) {x=ox, y=oy; break;}
		}
		cout << (1ULL<<min(__builtin_ctz(x), __builtin_ctz(y))) << '\n';
	}
}