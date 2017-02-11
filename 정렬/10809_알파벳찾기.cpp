#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
	string input;
	int result[26];

	cin >> input;
	for (int i = 0; i < 26; i++) result[i] = -1;
	for (int i = 0; i < input.size(); i++) {
		if (result[input[i] - 'a'] != -1) continue;
		result[input[i] - 'a'] = i;
	}

	for (int i = 0; i < 26; i++) printf("%d ", result[i]);
	printf("\n");

	return 0;
}