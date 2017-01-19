#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int maze[102][102];
queue <pair<int, int>> q;

void BFS(int x ,int y)
{
	q.push(make_pair(x, y));

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (maze[x][y + 1] == 1) {
			maze[x][y + 1] = maze[x][y] + 1;
			q.push(make_pair(x, y + 1));
		}

		if (maze[x + 1][y] == 1) {
			maze[x + 1][y] = maze[x][y] + 1;
			q.push(make_pair(x + 1, y));
		}

		if (maze[x - 1][y] == 1) {
			maze[x - 1][y] = maze[x][y] + 1;
			q.push(make_pair(x - 1, y));
		}

		if (maze[x][y - 1] == 1) {
			maze[x][y - 1] = maze[x][y] + 1;
			q.push(make_pair(x, y - 1));
		}
	}
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int row, col;
	char val;

	scanf("%d %d", &col, &row);

	for (int i = 0; i <= 101; i++) {
		for (int j = 0; j <= 101; j++) {
			maze[i][j] = -2;
		}
	}

	for (int i = 1; i <= col; i++) {
		val = getchar();
		for (int j = 1; j <= row; j++) {
			val = getchar();
			maze[i][j] = val - '0';
		}
	}

	maze[1][1] = 2;
	BFS(1,1);

	printf("%d\n", maze[col][row] - 1);

	return 0;
}