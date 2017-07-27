#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int set[10] = { 0 };
	string input;

	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		set[input[i] - '0']++;
	}

	int maxVal = 0, index;
	for (int i = 0; i < 10; i++) {
		if (maxVal < set[i]) {
			maxVal = set[i];
			index = i;
		}
	}

	if (index == 6 || index == 9) {
		if ((set[6] + set[9]) % 2 == 0) {
			maxVal = (set[6] + set[9]) / 2;
		}
		else {
			maxVal = (set[6] + set[9]) / 2 + 1;
		}
	}

	printf("%d\n", maxVal);
}