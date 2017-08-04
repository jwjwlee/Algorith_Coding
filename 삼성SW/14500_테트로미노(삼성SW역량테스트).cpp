#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int p[502][502], row, col;

// 모양 : ----
int case1()
{
	int ans = 0;

	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row - 3; j++) {
			int sum = 0;			
			sum = p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i][j + 3];
			ans = max(ans, sum);
		}
	}

	for (int i = 1; i <= col - 3; i++) {
		for (int j = 1; j <= row; j++) {
			int sum = 0;
			sum = p[i][j] + p[i + 1][j] + p[i + 2][j] + p[i + 3][j];
			ans = max(ans, sum);
		}
	}

	return ans;
}

//모양 : ___|
int case2()
{
	int ans = 0;

	for (int i = 2; i <= col; i++) {
		for (int j = 1; j <= row - 2; j++) {
			int sum = 0;
			sum += p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i - 1][j + 2];
			ans = max(ans, sum);
		}
	}

	for (int i = 1; i <= col - 1; i++) {
		for (int j = 1; j <= row - 2; j++) {
			int sum = 0;
			sum = p[i][j] + p[i + 1][j] + p[i][j + 1] + p[i][j + 2];
			ans = max(ans, sum);
		}
	}

	for (int i = 1; i <= col - 2; i++) {
		for (int j = 1; j <= row - 1; j++) {
			int sum = 0;
			sum = p[i][j] + p[i + 1][j] + p[i + 2][j] + p[i + 2][j + 1];
			ans = max(ans, sum);
		}
	}

	for (int i = 1; i <= col - 2; i++) {
		for (int j = 2; j <= row;  j++) {
			int sum = 0;
			sum = p[i][j] + p[i][j - 1] + p[i + 1][j] + p[i + 2][j];
			ans = max(ans, sum);
		}
	}	

	return ans;
}

int case6() {

	int ans = 0;

	for (int i = 1; i <= col - 2; i++) {
		for (int j = 1; j <= row - 1; j++) {
			int sum = 0;
			sum += p[i][j] + p[i][j + 1] + p[i + 1][j] + p[i + 2][j];
			ans = max(ans, sum);
		}
	}

	for (int i = 3; i <= col; i++) {
		for (int j = 1; j <= row - 1; j++) {
			int sum = 0;
			sum = p[i][j] + p[i][j + 1] + p[i - 1][j + 1] + p[i - 2][j + 1];
			ans = max(ans, sum);
		}
	}

	for (int i = 1; i <= col - 1; i++) {
		for (int j = 1; j <= row - 2; j++) {
			int sum = 0;
			sum = p[i][j] + p[i][j + 1] + p[i][j + 2] + p[i + 1][j + 2];
			ans = max(ans, sum);
		}
	}

	for (int i = 1; i <= col - 1; i++) {
		for (int j = 1; j <= row - 2; j++) {
			int sum = 0;
			sum = p[i][j] + p[i + 1][j] + p[i + 1][j + 1] + p[i + 1][j + 2];
			ans = max(ans, sum);
		}
	}

	return ans;

}

//모양 : _ -
int case3()
{
	int ans = 0;

	for (int i = 2; i <= col; i++) {
		for (int j = 1; j <= row - 2; j++) {

			int sum = 0;
			sum = p[i][j] + p[i][j + 1] + p[i - 1][j + 1] + p[i - 1][j + 2];
			ans = max(ans, sum);
		}
	}

	for (int i = 1; i <= col - 2; i++) {
		for (int j = 1; j <= row - 1; j++) {
			
			int sum = 0;
			sum = p[i][j] + p[i + 1][j] + p[i + 1][j + 1] + p[i + 2][j + 1];
			ans = max(ans, sum);
		}
	}

	for (int i = 1; i <= col - 1; i++) {
		for (int j = 1; j <= row - 2; j++) {

			int sum = 0;
			sum = p[i][j] + p[i][j + 1] + p[i + 1][j + 1] + p[i + 1][j + 2];
			ans = max(ans, sum);
		}
	}

	for (int i = 1; i <= col - 2; i++) {
		for (int j = 2; j <= row; j++) {

			int sum = 0;
			sum = p[i][j] + p[i + 1][j] + p[i + 1][j - 1] + p[i + 2][j - 1];
			ans = max(ans, sum);
		}
	}

	return ans;
}

//모양 : ㅗ
int case4()
{
	int ans = 0;
	for (int i = 2; i <= col; i++) {
		for (int j = 2; j <= row - 1; j++) {
			int sum = 0;
			sum = p[i][j] + p[i - 1][j] + p[i][j - 1] + p[i][j + 1];
			ans = max(ans, sum);
		}
	}

	for (int i = 1; i <= col - 1; i++) {
		for (int j = 2; j <= row - 1; j++) {
			int sum = 0;
			sum = p[i][j] + p[i][j - 1] + p[i][j + 1] + p[i + 1][j];
			ans = max(ans, sum);
		}
	}

	for (int i = 2; i <= col - 1; i++) {
		for (int j = 1; j <= row - 1; j++) {
			int sum = 0;
			sum = p[i][j] + p[i - 1][j] + p[i + 1][j] + p[i][j + 1];
			ans = max(ans, sum);
		}
	}

	for (int i = 2; i <= col - 1; i++) {
		for (int j = 2; j <= row; j++) {
			int sum = 0;
			sum = p[i][j] + p[i - 1][j] + p[i + 1][j] + p[i][j - 1];
			ans = max(ans, sum);
		}
	}

	return ans;
}

//모양 : 정사각형
int case5()
{
	int ans = 0;
	for (int i = 1; i <= col - 1; i++) {
		for (int j = 1; j <= row - 1; j++) {
			int sum = 0;
			sum = p[i][j] + p[i + 1][j] + p[i][j + 1] + p[i + 1][j + 1];
			ans = max(ans, sum);
		}
	}

	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &col, &row);
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			scanf("%d", &p[i][j]);
		}
	}
	
	printf("%d\n", max(max(max(case1(), case2()), max(case3(), case4())), max(case5(), case6())));
}
