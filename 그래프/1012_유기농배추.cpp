#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int map[51][51] = { 0 }, row, col;
int nx[4] = { 0, 0, 1, -1 }, ny[4] = { 1, -1, 0, 0 };
bool visit[51][51];

void DFS(int x, int y)
{
	if (x > col - 1 || y > row - 1 || x < 0 || y < 0) return;

	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {

		if (x + nx[i] > col - 1 || y + ny[i] > row - 1 || x + nx[i] < 0 || y + ny[i] < 0) continue;

		if (map[x + nx[i]][y + ny[i]] == 1 && visit[x + nx[i]][y + ny[i]] == false) {
			DFS(x + nx[i], y + ny[i]);
		}	
	}
}

int main()
{
	int caseNum, locNum, x, y;

	scanf("%d", &caseNum);
	while (caseNum--) {
		scanf("%d %d %d", &row, &col, &locNum);
		while (locNum--) {
			scanf("%d %d", &y, &x);
			map[x][y] = 1;
		}


		int ans = 0;
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				visit[i][j] = false;
			}
		}

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				if (map[i][j] == 1 && visit[i][j] == false) {
					DFS(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				map[i][j] = 0;
			}
		}
	}
}