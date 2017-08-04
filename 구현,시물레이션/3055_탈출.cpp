#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int col, row, time = 0;
	int nx[4] = { 0, 0, 1, -1 }, ny[4] = { 1, -1, 0, 0, };
	char map[51][51] = { 0 };
	bool Kvisit[51][51] = { 0 }, Wvisit[51][51] = { 0 };
	queue<pair<int, int>> q, Wq;

	scanf("%d %d", &col, &row);
	for (int i = 0; i < col; i++) {
		getchar();
		for (int j = 0; j < row; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'S') {
				q.push({ i, j });
			}
			if (map[i][j] == '*') {
				Wq.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
	
		int Wsz = Wq.size();
		while (Wsz--) {
			int x = Wq.front().first;
			int y = Wq.front().second;
			Wq.pop();

			for (int i = 0; i < 4; i++) {
				int mx = x + nx[i], my = y + ny[i];
				if (mx < 0 || mx >= col || my < 0 || my >= row) continue;
				if (map[mx][my] == '.' && Wvisit[mx][my] == false) {
					map[mx][my] = '*';
					Wvisit[mx][my] = true;
					Wq.push({ mx, my });
				}
			}	
		}

		int sz = q.size();
		while (sz--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int mx = x + nx[i], my = y + ny[i];
				if (mx < 0 || mx >= col || my < 0 || my >= row) continue;
				if (map[mx][my] == '.' && Kvisit[mx][my] == false) {
					Kvisit[mx][my] = true;
					q.push({ mx, my });
				}
				if (map[mx][my] == 'D') {
					printf("%d\n", time + 1);
					return 0;
				}
			}
		}
		time++;
	}
	printf("KAKTUS\n");
}