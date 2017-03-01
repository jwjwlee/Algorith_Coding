#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N, q[16][16] = { 0 }, result = 0;

void path(int curcol, int currow, int val, int cmp)
{
	//아래
	int col = curcol;
	while (col != N + 1) {
		if (q[col][currow] == cmp) q[col][currow] = val;
		col++;
	}
	//대각선우측
	col = curcol;
	int row = currow;
	while (row != N + 1 && col != N + 1) {
		if (q[col][row] == cmp) q[col][row] = val;
		col++; row++;
	}
	//대각선 좌측
	col = curcol;
	row = currow;
	while (row != 0 && col != N + 1) {
		if (q[col][row] == cmp) q[col][row] = val;
		col++; row--;
	}
}

int sol(int cur)
{
	for (int i = 1; i <= N; i++) {
		if (q[cur][i] == 0) {
			path(cur, i, cur, 0);
			if (cur == N) {
				path(cur, i, 0, cur);
				return 1;
			}
			result += sol(cur + 1);
			path(cur, i, 0, cur);
		}
	}
	return 0;
}

int main()
{
	scanf("%d", &N);
	sol(1);
	if (N == 1) printf("1\n");
	else printf("%d\n", result);

	return 0;
}