#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

/*
�ð����⵵ : O(n)
�������⵵ : O(n)
*/

int main()
{
	int case_num, k, val;

	scanf("%d %d", &case_num, &k);

	vector<int> num;

	for (int i = 0; i < case_num; i++) {
		scanf("%d", &val);
		num.push_back(val);
	}

	sort(num.begin(), num.end());

	cout << num[k - 1] << "\n";

	num.clear();
	return 0;
}