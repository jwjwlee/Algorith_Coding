#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int N, area[101][101], after[101][101];

void DFS(int x, int y)
{
	if (after[x][y + 1] != - 1 && y + 1 < N) {
		after[x][y + 1] = -1;
		DFS(x, y + 1);
	}
	
	if (after[x + 1][y] != -1 && x + 1 < N) {
		after[x + 1][y] = -1;
		DFS(x + 1, y);
	}

	if (after[x][y - 1] != -1 && y - 1 >= 0) {
		after[x][y - 1] = -1;
		DFS(x, y - 1);
	}

	if (after[x - 1][y] != -1 && x - 1 >= 0) {
		after[x - 1][y] = -1;
		DFS(x - 1, y);
	}

	return;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int maxH = 0, ans = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &area[i][j]);
			maxH = max(area[i][j], maxH);
		}
	}

	for (int k = 0; k <= maxH; k++) {

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				after[i][j] = area[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (after[i][j] <= k) {
					after[i][j] = -1;
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (after[i][j] != -1) {
					DFS(i, j);
					cnt++;
				}
			}
		}

		ans = max(ans, cnt);
	}

	printf("%d\n", ans);

}