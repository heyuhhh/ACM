#include <iostream>
using namespace std;
int grid[102][102];
bool marked[100][100];

int main()
{
	int h,w; cin >> h >> w;
	for (int i = 0; i < h+2; ++i)
		for (int j = 0; j < w+2; ++j)
			cin >> grid[i][j];

	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			if (grid[i][j] > 0)
			{
				marked[i][j] = true;
				for (int x = i; x < i+3; ++x)
					for (int y = j; y < j+3; ++y)
						if (0 <= x && x < h+2 && 0 <= y && y < w+2)
							grid[x][y]--;
			}
		}
	}
	for (int i = 0; i < h+2; ++i)
		for (int j = 0; j < w+2; ++j)
			if (grid[i][j] != 0)
				cout << "impossible" << endl, exit(0);
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
			if (marked[i][j])
				cout << 'X';
			else
				cout << '.';
 		cout << endl;
	}
}
