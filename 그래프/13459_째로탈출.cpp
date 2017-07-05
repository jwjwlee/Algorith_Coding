#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, Rx, Ry, Bx, By;
char b[11][11];
int check[11][11][11][11] = { 0 };
int mvx[4] = { 0, 0, 1, -1 };
int mvy[4] = { 1, -1, 0, 0 };

int Play()
{
	int cnt = 0;
	queue < pair<pair<int, int>, pair<int, int>>> q;

	q.push({ {Rx, Ry}, {Bx, By} });
	check[Rx][Ry][Bx][By] = 1;

	while (!q.empty()) {
		
		int sz = q.size();
		
		while (sz--) {
			
			int rx = q.front().first.first;
			int ry = q.front().first.second;
			int bx = q.front().second.first;
			int by = q.front().second.second;
			q.pop();

			//성공
			if (b[rx][ry] == 'O') return 1;

			for (int i = 0; i < 4; i++) {
				
				int rsx = rx, rsy = ry, bsx = bx, bsy = by;
				bool flag = false;

				while (b[rsx + mvx[i]][rsy + mvy[i]] != '#' && b[rsx][rsy] != 'O') {
					rsx += mvx[i];
					rsy += mvy[i];
				}
				while (b[bsx + mvx[i]][bsy + mvy[i]] != '#' && b[bsx][bsy] != 'O') {
					bsx += mvx[i];
					bsy += mvy[i];
					if (b[bsx][bsy] == 'O') flag = true;
				}

				if (rsx == bsx && rsy == bsy) {

					//우
					if (i == 0) {
						if (ry > by) bsy--;
						else rsy--;
					}

					//좌
					else if (i == 1) {
						if (ry > by) rsy++;
						else bsy++;
					}

					//아래
					else if (i == 2) {
						if (rx > bx) bsx--;
						else rsx--;
					}

					//위
					else {
						if (rx > bx) rsx++;
						else bsx++;

					}
				}
				if (flag == true) continue;
				if (check[rsx][rsy][bsx][bsy] != 1) {
					q.push({ {rsx,rsy}, {bsx,bsy} });
					check[rsx][rsy][bsx][bsy] = 1;
				}
			}		
		}
		cnt++;
		if (cnt > 10) return 0;
	}

	return 0;
}


int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < M; j++) {
			scanf("%c", &b[i][j]);			
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (b[i][j] == 'R') {
				Rx = i; Ry = j;
			}
			if (b[i][j] == 'B') {
				Bx = i; By = j;
			}
		}
	}

	printf("%d\n", Play());
}