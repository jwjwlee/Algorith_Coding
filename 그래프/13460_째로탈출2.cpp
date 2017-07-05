#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int N, M, cnt = 0;
	char b[11][11];
	bool check[11][11][11][11] = { 0 };
	int mvx[4] = { 0, 0, 1, -1 };
	int mvy[4] = { 1, -1, 0, 0 };
	queue<pair<pair<int, int>, pair<int, int>>> q;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < M; j++) {
			scanf("%c", &b[i][j]);
		}
	}

	int rx, ry, bx, by;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (b[i][j] == 'R') {
				rx = i; ry = j;
			}
			if (b[i][j] == 'B') {
				bx = i; by = j;
			}
		}
	}

	q.push({ {rx, ry}, {bx, by} });
	check[rx][ry][bx][by] = true;
	while (!q.empty()) {

		int sz = q.size();
		while (sz--) {

			rx = q.front().first.first;
			ry = q.front().first.second;
			bx = q.front().second.first;
			by = q.front().second.second;
			q.pop();

			if (b[rx][ry] == 'O') {
				printf("%d\n", cnt);
				return 0;
			}

			for (int i = 0; i < 4; i++) {

				int nrx = rx, nry = ry, nbx = bx, nby = by;
				while (b[nrx + mvx[i]][nry + mvy[i]] != '#' && b[nrx][nry] != 'O') {
					nrx += mvx[i];
					nry += mvy[i];
				}
				while (b[nbx + mvx[i]][nby + mvy[i]] != '#' && b[nbx][nby] != 'O') {
					nbx += mvx[i];
					nby += mvy[i];
				}
				
				if (b[nbx][nby] == 'O') continue;

				if (nrx == nbx && nry == nby) {
					switch (i)
					{
					case 0:
						if (ry > by) nby--;
						else nry--;
						break;
					case 1:
						if (ry > by) nry++;
						else nby++;
						break;
					case 2:
						if (rx > bx) nbx--;
						else nrx--;
						break;
					case 3:
						if (rx > bx) nrx++;
						else nbx++;
						break;
					}
				}
				
				if (check[nrx][nry][nbx][nby] == false) {
					q.push({ { nrx, nry },{ nbx, nby } });
					check[nrx][nry][nbx][nby] = true;
				}
			}
		}
		cnt++;
		if (cnt > 10) {
			printf("-1\n");
			return 0;
		}
	}
	printf("-1\n");
}