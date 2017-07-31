#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int process(int arr[21][21]);
int N, t = 0;
int input[21][21];


int Right(int b[21][21])
{
	for(int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			for (int j = N - 1; j > 0; j--) {
				if (b[i][j] == 0 && b[i][j - 1] != 0)
					swap(b[i][j], b[i][j - 1]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j > 0; j--) {
			if (b[i][j] == b[i][j - 1]) {
				b[i][j] *= 2;
				b[i][j - 1] = 0;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			for (int j = N - 1; j > 0; j--) {
				if (b[i][j] == 0 && b[i][j - 1] != 0)
					swap(b[i][j], b[i][j - 1]);
			}
		}
	}
	t++;
	return process(b);
}

int Left(int b[21][21])
{
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			for (int j = 0; j < N - 1; j++) {
				if (b[i][j] == 0 && b[i][j + 1] != 0)
					swap(b[i][j], b[i][j + 1]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (b[i][j] == b[i][j + 1]) {
				b[i][j] *= 2;
				b[i][j + 1] = 0;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			for (int j = 0; j < N - 1; j++) {
				if (b[i][j] == 0 && b[i][j + 1] != 0)
					swap(b[i][j], b[i][j + 1]);
			}
		}
	}
	t++;
	return process(b);
}

int Up(int b[21][21])
{
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			for (int j = 0; j < N - 1; j++) {
				if (b[j][i] == 0 && b[j + 1][i] != 0)
					swap(b[j][i], b[j + 1][i]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (b[j][i] == b[j + 1][i]) {
				b[j][i] *= 2;
				b[j + 1][i] = 0;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			for (int j = 0; j < N - 1; j++) {
				if (b[j][i] == 0 && b[j + 1][i] != 0)
					swap(b[j][i], b[j + 1][i]);
			}
		}
	}
	t++;
	return process(b);

}

int Down(int b[21][21])
{
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			for (int j = N - 1; j > 0; j--) {
				if (b[j][i] == 0 && b[j - 1][i] != 0)
					swap(b[j][i], b[j - 1][i]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j > 0; j--) {
			if (b[j][i] == b[j - 1][i]) {
				b[j][i] *= 2;
				b[j - 1][i] = 0;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			for (int j = N - 1; j > 0; j--) {
				if (b[j][i] == 0 && b[j - 1][i] != 0)
					swap(b[j][i], b[j - 1][i]);
			}
		}
	}
	t++;
	return process(b);
}

int process(int arr[21][21])
{
	int ans = 0;
	int temp[21][21];

	if (t == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				if (ans < arr[i][j]) ans = arr[i][j];
		}
		return ans;
	}

	int L = 0, R = 0, U = 0, D = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			temp[i][j] = arr[i][j];
	}

	L = max(L, Left(temp));
	t--;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			temp[i][j] = arr[i][j];
	}
	R = max(R, Right(temp));
	t--;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			temp[i][j] = arr[i][j];
	}
	U = max(U, Up(temp));
	t--;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			temp[i][j] = arr[i][j];
	}
	D = max(D, Down(temp));
	t--;

	ans = max(max(L, R), max(U, D));
	return ans;
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &input[i][j]);
		}
	}
	printf("%d\n", process(input));

	return 0;
}