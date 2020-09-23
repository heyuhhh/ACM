#include <bits/stdc++.h>

using namespace std;

int c[200][200];
bool m[200][200];

int main(){
	memset(m,0,sizeof(m));
	int h,w; cin >> h >> w; h+=2; w+=2;
	for (int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> c[i][j];
	for (int i = 0; i < h-2; i++) for(int j = 0; j < w-2; j++) if (c[i][j]){
		m[i][j] = true;
		for (int ni = i; ni < i+3; ni++) for(int nj = j; nj < j+3; nj++) c[ni][nj]--;
	}
	
	for (int i = 0; i < h; i++)	for(int j = 0; j < w; j++) if (c[i][j]){cout << "impossible" << endl; return 0;}

	for (int i = 0; i < h-2; i++){
		for(int j = 0; j < w-2; j++) cout << (m[i][j] ? 'X' : '.');
		cout << endl;
	}
	
}
