#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int land[51][51];
int cnt = 0;

int DFS(int x, int y)
{
	cnt++;
	land[x][y] = -1;
	if (land[x][y + 1] == 1) DFS(x, y + 1);
	if (land[x + 1][y] == 1) DFS(x + 1, y);
	if (land[x][y - 1] == 1) DFS(x, y - 1);
	if (land[x - 1][y] == 1) DFS(x - 1, y);
	if (land[x + 1][y + 1] == 1) DFS(x + 1, y + 1);
	if (land[x - 1][y + 1] == 1) DFS(x - 1, y + 1);
	if (land[x + 1][y - 1] == 1) DFS(x + 1, y - 1);
	if (land[x - 1][y - 1] == 1) DFS(x - 1, y - 1);

	return cnt;
}


int main()
{
	int width = -1, height = -1, n = 0, result = 0;
	char val;

	while (width != 0 && height != 0) {
		scanf("%d %d", &width, &height);
		if (height == 0 && width == 0) break;


		result = 0;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				land[i][j] = 0;
			}
		}


		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				scanf("%d", &land[i][j]);
			}
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (land[i][j] == 1) {
					result++;
					DFS(i, j);
				}
			}
		}

		printf("%d\n", result);
	}

	return 0;
}