#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

/*
시간복잡도 : O(N^3)
공간복잡도 : O(N)
*/

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif 

	int size, val, result, max = 0;
	vector<int> vec;

	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &val);
		vec.push_back(val);
	}
	
	sort(vec.begin(), vec.end());

	do {
		result = 0;

		for (int i = 0; i < vec.size() - 1; i++) {
			result += abs(vec[i] - vec[i + 1]);
		}

		if (max < result) max = result;

	}while(next_permutation(vec.begin(), vec.end()));
	
	
	printf("%d\n", max);

	return 0;
}