#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int col, row, cnt = 0, maxAns = 0;
int map[9][9] = { 0 }, temp[9][9] = { 0 };
int nx[4] = { 0, 0, 1, -1 }, ny[4] = { 1, -1, 0, 0 };

int safeArea()
{
	int ans = 0;

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (temp[i][j] == 0)
				ans++;
		}
	}

	return ans;
}

void virusArea()
{
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			temp[i][j] = map[i][j];
		}
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (temp[i][j] == 2) 
				q.push({ i, j });
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int mx = x + nx[i];
			int my = y + ny[i];
			if (mx < 0 || mx >= col || my < 0 || my >= row) continue;

			if (temp[mx][my] == 0) {
				temp[mx][my] = 2;
				q.push({ mx, my });
			}
		}
	}
}

void makeWall() 
{
	if (cnt == 3) {
		virusArea();
		maxAns = max(maxAns, safeArea());
		return;
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				cnt++;	
				makeWall();
				cnt--;
				map[i][j] = 0;
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &col, &row);
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	makeWall();

	printf("%d\n", maxAns);
}
