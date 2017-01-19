#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

/*
시간복잡도 : O(nlogn)
공간복잡도 : O(n)
*/

int main()
{
	int case_num, count = 1, flag = 0, n = 0;
	int char_cnt[27] = { 0 };
	char oddchar = NULL;
	vector <char> temp;
	string name;

	cin >> name;

	for (int i = 0; i < name.size(); i++) {
		char_cnt[name[i] - 'A']++;
	}

	for (int i = 0; i < 27; i++) {
		if (char_cnt[i] % 2 != 0) {
			oddchar = i + 'A';
			flag++;
		}
	}

	if (flag > 1) {
		printf("I'm Sorry Hansoo\n");
		return 0;
	}

	for (int i = 0; i < 27; i++) {
		while (char_cnt[i] != 0) {
			if (char_cnt[i] != 1) {
				printf("%c", i + 'A');
				temp.push_back(i + 'A');
				char_cnt[i] -= 2;
			}
			else
				break;
		}
	}

	if (oddchar != NULL)
		printf("%c", oddchar);

	for (int i = temp.size() - 1; i >= 0; i--) {
		printf("%c", temp[i]);
	}
	printf("\n");

	return 0;
}
