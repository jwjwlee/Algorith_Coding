#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

/*
시간복잡도 : O(n)
공간복잡도 : O(n)
*/

int main()
{
	string input;
	deque<char> alpha, alpha2;

	for (int i = 0; i < 26; i++) {
		alpha.push_back(i + 'a');
		alpha2.push_back(i + 'A');
	}

	getline(cin, input);


	for (int i = 0; i < input.size(); i++) {
		if (input[i] > 64 && input[i] < 91) {
			while (input[i] != alpha2.front()) {
				alpha2.push_back(alpha2.front());
				alpha2.pop_front();
			}
			for (int i = 0; i < 13; i++) {
				alpha2.push_back(alpha2.front());
				alpha2.pop_front();
			}
			input[i] = alpha2.front();
		}
		
		else if (input[i] == ' ') continue;
		else if (input[i] > 47 && input[i] < 58) continue;

		else {
			while (input[i] != alpha.front()) {
				alpha.push_back(alpha.front());
				alpha.pop_front();
			}
			for (int i = 0; i < 13; i++) {
				alpha.push_back(alpha.front());
				alpha.pop_front();
			}
			input[i] = alpha.front();
		}
	}

	for (int i = 0; i < input.size(); i++) {
		cout << input[i];
	}	
	printf("\n");
	
	return 0;
}