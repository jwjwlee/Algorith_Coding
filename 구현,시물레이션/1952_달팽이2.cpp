#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


bool map[101][101];
int col, row, ans = 0;

void dfs(int x, int y, char dir)
{
	map[x][y] = true;

	if (map[x][y + 1] && map[x][y - 1] && map[x - 1][y] && map[x + 1][y]) {
		printf("%d\n", ans);
		exit(0);
	}

	if (dir == 'R') {
		if (y + 1 > row-1 || map[x][y + 1] == true) {
			ans++;
			dfs(x + 1, y, 'D');
		}
		else dfs(x, y + 1, 'R');
	}

	if (dir == 'D') {
		if (x + 1 > col-1 || map[x + 1][y] == true) {
			ans++;
			dfs(x, y - 1, 'L');
		}
		else dfs(x + 1, y, 'D');
	}

	if (dir == 'L') {
		if (y - 1 < 0 || map[x][y - 1] == true) {
			ans++;
			dfs(x - 1, y, 'U');
		}
		else dfs(x, y - 1, 'L');
	}

	if (dir == 'U') {
		if (x - 1 < 0 || map[x - 1][y] == true) {
			ans++;
			dfs(x, y + 1, 'R');
		}
		else dfs(x - 1, y, 'U');
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &col, &row);
	if (row == 2 && col != 2) printf("3\n");
	else if (col == 2) printf("2\n");
	else dfs(0, 0, 'R');
}