#include <iostream>
#include <cstdio>
using namespace std;

int map[52][52], ans = 0;

//0:À§
//1:¿À
//2:¾Æ·¡
//3:¿Þ

void step(int x, int y, int d)
{
	map[x][y] = 2;

	if (map[x][y - 1] != 0 && map[x][y + 1] != 0 && map[x - 1][y] != 0 && map[x + 1][y] != 0) {
		if (d == 0) {
			if (map[x + 1][y] == 1) {
				printf("%d\n", ans + 1);
				exit(0);
			}
			step(x + 1, y, d);
		}
		if (d == 1) {
			if (map[x][y - 1] == 1) {
				printf("%d\n", ans + 1);
				exit(0);
			}
			step(x, y - 1, d);
		}
		if (d == 2) {
			if (map[x - 1][y] == 1) {
				printf("%d\n", ans + 1);
				exit(0);
			}
			step(x - 1, y, d);
		}
		if (d == 3) {
			if (map[x][y + 1] == 1) {
				printf("%d\n", ans + 1);
				exit(0);
			}
			step(x, y + 1, d);
		}
	}

	if (d == 0 && map[x][y - 1] == 0) {
		ans++;
		step(x, y - 1, 3);
	}

	else if (d == 1 && map[x - 1][y] == 0) {
		ans++;
		step(x - 1, y, 0);
	}

	else if (d == 2 && map[x][y + 1] == 0) {
		ans++;
		step(x, y + 1, 1);
	}

	else if (d == 3 && map[x + 1][y] == 0) {
		ans++;
		step(x + 1, y, 2);
	}	

	else {
		if (d == 0) step(x, y, 3);
		if (d == 1) step(x, y, 0);
		if (d == 2) step(x, y, 1);
		if (d == 3) step(x, y, 2);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	int col, row, sx, sy, dir;

	scanf("%d %d", &col, &row);
	scanf("%d %d %d", &sx, &sy, &dir);


	for (int i = 0; i <= col + 1; i++) {
		for (int j = 0; j <= row + 1; j++) {
			map[i][j] = 1;
		}
	}

	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	step(sx + 1, sy + 1, dir);
}	
