#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char b[21][21];
int flag[26] = { 0 }, ret = 0,temp = 0, row, col;
int sol(int x, int y)
{
	int cnt = 0;
	flag[b[x][y] - 'A'] = 1;
	if (x + 1 <= col) {
		if (flag[b[x + 1][y] - 'A'] == 0) {
			ret = sol(x + 1, y);
			if (cnt < ret) cnt = ret;
		}
	}
	if (x - 1 >= 1) {
		if (flag[b[x - 1][y] - 'A'] == 0) {
			ret = sol(x - 1, y);
			if (cnt < ret) cnt = ret;
		}
	}
	if (y + 1 <= row) {
		if (flag[b[x][y + 1] - 'A'] == 0) {
			ret = sol(x, y + 1);
			if (cnt < ret) cnt = ret;
		}
	}
	if (y - 1 >= 1) {
		if (flag[b[x][y - 1] - 'A'] == 0) {
			ret = sol(x, y - 1);
			if (cnt < ret) cnt = ret;
		}
	}
	flag[b[x][y] - 'A'] = 0;

	return cnt + 1;
}

int main()
{
	char input;
	scanf("%d %d", &col, &row);
	for (int i = 1; i <= col; i++) {
		getchar();
		for (int j = 1; j <= row; j++) {
			scanf("%c", &b[i][j]);
		}
	}
	printf("%d\n", sol(1, 1));

	return 0;
}

/************************************************************************************************************************************/
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char b[21][21];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int flag[26] = { 0 }, ret = 0, row, col;
int sol(int x, int y)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx <= col && nx > 0 && ny <= row && ny > 0) {
			if (flag[b[nx][ny] - 'A'] == 0) {
				flag[b[nx][ny] - 'A'] = 1;
				int ret = sol(nx, ny);
				if (cnt < ret) cnt = ret;
				flag[b[nx][ny] - 'A'] = 0;
			}
		}
	}
	return cnt + 1;
}

int main()
{
	char input;
	scanf("%d %d", &col, &row);
	for (int i = 1; i <= col; i++) {
		getchar();
		for (int j = 1; j <= row; j++) {
			scanf("%c", &b[i][j]);
		}
	}
	flag[b[1][1] - 'A'] = 1;
	printf("%d\n", sol(1, 1));

	return 0;
}
*/