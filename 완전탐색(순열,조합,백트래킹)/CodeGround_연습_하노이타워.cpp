#include <iostream>
using namespace std;

/*
1. ���1���� N-1�� ������ ���3�� �̿��Ͽ� ���2�� �ű��.
2. ���1���� 1�� ������ ���3���� �ű��.
3. ���2���� N-1�� ������ ���1�� �̿��Ͽ� ���3���� �ű��.	
*/

void move(int n, int from, int by, int to)
{
	if (n == 1) {
		cout << from << " -> " << to << endl;	
	}
	else {
		move(n - 1, from, to, by);
		cout << from << " -> " << to << endl;
		move(n - 1, by, from, to);
	}
}

int main(int argc, char** argv)
{
	int T, test_case;


	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int N;
		cin >> N;
		cout << "Case #" << test_case + 1 << endl;
		move(N, 1, 2, 3);
	}

	return 0;
}



