#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[101][101] = { 0 };
int row, col, area;
vector<int> v;

void DFS(int x, int y)
{
	map[x][y] = 1;
	area++;

	if (map[x][y + 1] == 0 && y + 1 < row) DFS(x, y + 1);
	
	if (map[x + 1][y] == 0 && x + 1 < col) DFS(x + 1, y);
	
	if (map[x - 1][y] == 0 && x - 1 >= 0) DFS(x - 1, y);
	
	if (map[x][y - 1] == 0 && y - 1 >= 0) DFS(x, y - 1);

	return;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int K, x1, x2, y1, y2, ans = 0;
	
	scanf("%d %d %d", &col, &row, &K);
	
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int j = x1; j < x2; j++) {
			for (int m = y1; m < y2; m++) {
				map[m][j] = 1;
			}
		}
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (map[i][j] == 0) {				
				DFS(i, j);
				v.push_back(area);
				ans++;
				area = 0;
			}
		}
	}
	
	printf("%d\n", ans);

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}

	return 0;
}