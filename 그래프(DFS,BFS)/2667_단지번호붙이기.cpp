#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int apt[26][26];
int cnt = 0;

int DFS(int x, int y)
{
	cnt++;
	apt[x][y] = -1;
	if (apt[x][y + 1] == 1) DFS(x, y + 1);
	if (apt[x + 1][y] == 1) DFS(x + 1, y);	
	if (apt[x][y - 1] == 1) DFS(x, y - 1);
	if (apt[x - 1][y] == 1) DFS(x - 1, y);

	return cnt;
}


int main()	
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int size, n = 0, result[625] = { 0 };
	char val;

	scanf("%d", &size);

	for (int i = 0; i < size; i++) {
		val = getchar();
		for (int j = 0; j < size; j++) {
			val = getchar();
			apt[i][j] = val - '0';
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (apt[i][j] == 1) {
				cnt = 0;
				result[n++] = DFS(i, j);
			}
		}
	}

	sort(result, result + n);
		
	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
		printf("%d\n", result[i]);
	}	

	return 0;
}