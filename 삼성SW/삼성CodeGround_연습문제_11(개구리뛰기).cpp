// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
using namespace std;

int arr[1000001];
int main(int argc, char** argv) {
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
	int N, rock, jump;

	scanf("%d", &TC);	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		scanf("%d", &N);
		for (int i = 0; i <= N; i++) {
			arr[i] = 0;
		}

		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
		}
		scanf("%d", &jump);

		int cur = 0;
		int ans = 0;
		bool flag = false;
		for (int i = 0; i < N; i++) {
			if (arr[i] > cur + jump) {
				flag = true;
				break;
			}
			if (arr[i + 1] > cur + jump) {
				ans++;
				cur = arr[i];	
			}
		}
		if (cur + jump < arr[N]) flag = true;
		else ans++;

		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		if (flag == true) printf("-1\n");
		else printf("%d\n", ans);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}