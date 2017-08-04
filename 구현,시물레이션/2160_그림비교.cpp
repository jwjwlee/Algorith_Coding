#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;
	char p[251][8];
	char input;

	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		for (int i = 5 * k; i < 5 * k + 5; i++) {
			getchar();
			for (int j = 0; j < 7; j++) {
				scanf("%c", &p[i][j]);
			}
		}
	}
		
	int max = 0, paint1, paint2;
	for (int k = 0; k < N; k++) {
		for (int l = k + 1; l < N; l++) {
			int cnt = 0;
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 7; j++) {
					if (p[i + 5 * k][j] == p[i + 5 * l][j]) {
						cnt++;
					}
				}
			}

			if (max < cnt) {
				max = cnt;
				paint1 = k; paint2 = l;
			}
		}
	}

	printf("%d %d\n", paint1 + 1, paint2 + 1);
}