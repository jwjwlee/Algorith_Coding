#include <iostream>
using namespace std;

/*
1. 기둥1에서 N-1개 원반을 기둥3을 이용하여 기둥2로 옮긴다.
2. 기둥1에서 1개 원반을 기둥3으로 옮긴다.
3. 기둥2에서 N-1개 원반을 기둥1을 이용하여 기둥3으로 옮긴다.	
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



