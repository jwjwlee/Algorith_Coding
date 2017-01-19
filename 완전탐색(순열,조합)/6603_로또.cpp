#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> result;

void Combination(vector<int> &temp, int index, int n)
{
	if (n == 6) {
		for (int i = 0; i < 6; i++) {
			printf("%d ", result[i]);
		}
		printf("\n");
		return;
	}

	if (temp.size() == index) return;
	result.push_back(temp[index]);
	Combination(temp, index + 1, n + 1);
	result.pop_back();
	Combination(temp, index + 1, n);
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int groupN = 1, val;
	vector<int> vec;

	
	while (1) {
		vec.clear();

		scanf("%d", &groupN);
		if (groupN == 0) break;
		for (int i = 0; i < groupN; i++) {
			scanf("%d", &val);
			vec.push_back(val);
		}

		Combination(vec, 0, 0);
		printf("\n");

	}
	return 0;
}