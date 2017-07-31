// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv) {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;
	int rB, stT, endT, stD, endD, N;
	double x, y;
	int angle[22] = {0, 9, 27, 45, 63, 81, 99, 117, 135, 153,
						171, 189, 207, 225, 243, 261, 279, 297, 315, 333, 351};
	int score[22] = {6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10, 6};
	
	scanf("%d", &TC);	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.		
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
		
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n%d\n", test_case, ans);	// cout ��� ����

	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}