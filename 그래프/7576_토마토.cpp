#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int box[1002][1002];
queue <pair<int, int>> q;

void BFS() 
{
	int x, y;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		if (box[x][y + 1] == 0) {
			box[x][y + 1] = box[x][y] + 1;
			q.push(make_pair(x, y + 1));
		}

		if (box[x + 1][y] == 0) {
			box[x + 1][y] = box[x][y] + 1;
			q.push(make_pair(x + 1, y));
		}

		if (box[x - 1][y] == 0) {
			box[x - 1][y] = box[x][y] + 1;
			q.push(make_pair(x - 1, y));
		}

		if (box[x][y - 1] == 0) {
			box[x][y - 1] = box[x][y] + 1;
			q.push(make_pair(x, y - 1));
		}
	}
}

int main()
{
	int row, col, result = 0, flag = 0;

	scanf("%d %d", &row, &col);

	for (int i = 0; i <= 1001; i++) {
		for (int j = 0; j <= 1001; j++) {
			box[i][j] = -2;
		}
	}

	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			scanf("%d", &box[i][j]);
		}
	}

	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			if (box[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	BFS();

	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			if (box[i][j] == 0) flag = -1;
			if (box[i][j] > result)
				result = box[i][j];
		}
	}

	if (flag == -1) printf("-1\n");
	else
		printf("%d\n", result - 1);

	return 0;
}