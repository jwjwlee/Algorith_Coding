	#include <iostream>
	#include <stdio.h>
	#include <algorithm>
	using namespace std;

	int matrix[301][301];

	int main()
	{
	#ifdef _CONSOLE
		freopen("input.txt", "r", stdin);
	#endif

		int row, col, sumN, s1, s2, e1, e2, result;
	
		scanf("%d %d", &col, &row);
		for (int i = 1; i <= col; i++) {
			for (int j = 1; j <= row; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}

		scanf("%d", &sumN);
		for (int i = 0; i < sumN; i++) {
			scanf("%d %d %d %d", &s1, &s2, &e1, &e2);

			result = 0;
			for (int j = s1; j <= e1; j++) {
				for (int k = s2; k <= e2; k++) {
					result += matrix[j][k];
				}
			}
	
			printf("%d\n", result);	
		}

		return 0;
	}