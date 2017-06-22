// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
	int rB, stT, endT, stD, endD, N;
	double x, y;
	int angle[22] = {0, 9, 27, 45, 63, 81, 99, 117, 135, 153,
						171, 189, 207, 225, 243, 261, 279, 297, 315, 333, 351};
	int score[22] = {6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10, 6};
	
	scanf("%d", &TC);	// cin 사용 가능
	for (test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.		
		scanf("%d %d %d %d %d", &rB, &stT, &endT, &stD, &endD);
		scanf("%d", &N);

		int ans = 0;
		for (int i = 0; i < N; i++) {
			scanf("%lf %lf", &x, &y);

			double dist = sqrt(x*x + y*y);
			double theta; 
			if (x != 0 && y != 0) {
				theta = atan(y / x);
				theta *= 180 / 3.141592;
				if (x < 0 && y > 0) {
					theta = atan(-x / y);
					theta *= 180 / 3.141592;
					theta += 90;
				}
				if (x > 0 && y < 0) {
					theta = atan(x / (-y));
					theta *= 180 / 3.141592;
					theta += 270;
				}
				if (x < 0 && y < 0) {
					theta = atan(-y / -x);
					theta *= 180 / 3.141592;
					theta += 180;
				}
			}
			else if(x == 0) {
				if (y > 0) theta = 90;
				else theta = 270;
			}
			else {
				if (x > 0) theta = 0;
				else theta = 180;
			}

			if (dist <= rB)
				ans += 50;
			else if (dist >= stT && dist <= endT) {
				for (int j = 0; j < 21; j++) {
					if (theta < angle[j]) {
						ans += score[j - 1] * 3;
						break;
					}
				}
			}
			else if (dist >= stD && dist <= endD) {
				for (int j = 0; j < 21; j++) {
					if (theta < angle[j]) {
						ans += score[j - 1] * 2;
						break;
					}
				}
			}
			else if (dist >= endD) 
				continue;
			else {
				for (int j = 0; j < 21; j++) {
					if (theta < angle[j]) {
						ans += score[j - 1];
						break;
					}
				}
			}
		}
		
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n%d\n", test_case, ans);	// cout 사용 가능

	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}