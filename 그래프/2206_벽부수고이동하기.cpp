#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int map[1001][1001] = { 0 };
int mvx[4] = { 0, 0, 1, -1 };
int mvy[4] = { 1, -1, 0, 0 };
bool visit[1001][1001];
bool crackChk[1001][1001];

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int N, M;
	char input;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < M; j++) {
			scanf("%c", &input);
			map[i][j] = input - '0';
		}
	}

	queue<pair<pair<int, int>, pair<int, int>>> q;

	q.push({ { 0, 0 }, { 0, 0 } });
	visit[0][0] = true;

	while (!q.empty()) {

		int qx = q.front().first.first;
		int qy = q.front().first.second;
		int qcrack = q.front().second.first;
		int qcnt = q.front().second.second;
		q.pop();

		if (qx == N - 1 && qy == M - 1) {
			printf("%d\n", qcnt + 1);
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int x = qx, y = qy, crack = qcrack, cnt = qcnt;
			int nx = x + mvx[i], ny = y + mvy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			
			if (visit[nx][ny] == false) {
				if (map[nx][ny] == 0) {
					cnt += 1;
					q.push({ { nx, ny },{ crack, cnt } });
					visit[nx][ny] = true;
					crackChk[nx][ny] = crack;
				}

				else {
					if (crack == 0) {
						cnt += 1;
						q.push({ { nx, ny },{ 1, cnt } });
						visit[nx][ny] = true;
						crackChk[nx][ny] = true;
					}
				}
			}

			else {
				if (crack == 0 && map[nx][ny] == 0 && crackChk[nx][ny] == true) {
					cnt += 1;
					q.push({ { nx, ny },{ crack, cnt } });
					crackChk[nx][ny] = false;
				}
			}
		}
	}	
	printf("-1\n");
}