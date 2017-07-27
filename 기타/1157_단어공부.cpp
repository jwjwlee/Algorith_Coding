#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	string input;
	int alpha[27] = { 0 };
	
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] > 96) input[i] -= 32;
		alpha[input[i] - 'A']++;		
	}

	int maxVal = 0, res;
	for (int i = 0; i < 27; i++) {
		if (maxVal < alpha[i]) {
			maxVal = alpha[i];
			res = i;
		}
	}

	int cnt = 0;
	for (int i = 0; i < 27; i++) {
		if (alpha[i] == maxVal) cnt++;
	}

	if (cnt > 1) printf("?\n");
	else printf("%c\n", res + 'A');
}