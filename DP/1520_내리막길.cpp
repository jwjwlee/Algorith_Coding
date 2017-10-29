#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int map[501][501];
int dp[501][501];
int mx[4] = { 1, -1, 0, 0 };
int my[4] = { 0, 0, 1, -1 };
bool visit[501][501];
int col, row;

int dfs(int x, int y)
{
	if (x == 0 && y == 0) return 1;
	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;
	for(int i = 0; i < 4; i++) {
		int nx = x + mx[i];
		int ny = y + my[i];
		
		if (nx >= col || nx < 0 || ny >= row || ny < 0) continue;

		if (map[nx][ny] > map[x][y]) {
			dp[x][y] += dfs(nx, ny);
		}
	}

	return dp[x][y];
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d %d", &col, &row);

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			dp[i][j] = -1;
		}
	}

	printf("%d\n", dfs(col - 1, row - 1));

}