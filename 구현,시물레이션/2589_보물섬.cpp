#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

char map[51][51];
bool visit[51][51];
int col, row;
int nx[4] = { 0, 0, 1, -1 }, ny[4] = { 1, -1, 0, 0 };
queue<pair<pair<int, int>, int>> q;

int bfs(int x, int y)
{
	int ret = 0;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
		ret = max(ret, time);
		q.pop();

		time++;
		for (int i = 0; i < 4; i++) {
			int mx = x + nx[i];
			int my = y + ny[i];

			if (mx >= col || mx < 0 || my < 0 || my >= row) continue;
			if (map[mx][my] == 'L' && visit[mx][my] == false) {
				q.push({ { mx, my }, time });
				visit[mx][my] = true;
			}
		}
	}

	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &col, &row);
	for (int i = 0; i < col; i++) {
		getchar();
		for (int j = 0; j < row; j++) {
			scanf("%c", &map[i][j]);
		}
	}

	int ans = 0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			if (map[i][j] == 'L') {
				q.push({ {i, j}, 0 });
				visit[i][j] = true;
				ans = max(ans, bfs(i ,j));
				
				for (int i = 0; i < col; i++) {
					for (int j = 0; j < row; j++) {
						visit[i][j] = false;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
}