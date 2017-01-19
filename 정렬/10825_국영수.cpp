#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

/*
시간복잡도 : O(n)
공간복잡도 : O(n)
*/

struct student {
	string name;
	int kor, eng, math, flag = 0;
}info[100000];

bool cmp(const student &a, const student &b)
{
	if (a.kor > b.kor)
		return true;

	else if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math)
				return a.name < b.name;
			else
				return a.math > b.math;
		}
		else
			return a.eng < b.eng;
	}

	else
		return false;
}

int main()
{
	int case_num;
	scanf("%d", &case_num);

	for (int i = 0; i < case_num; i++) {
		cin >> info[i].name >> info[i].kor >> info[i].eng >> info[i].math;
	}

	sort(info, info + case_num, cmp);

	for (int i = 0; i < case_num; i++) {
		cout << info[i].name << "\n";
	}

	return 0;
}