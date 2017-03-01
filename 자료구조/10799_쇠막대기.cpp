#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stack>
using namespace std;

/*
공간복잡도 : O(n)
시간복잡도 : O(n)
*/

int main()
{
	stack <char> st;
	stack <char> all;
	char input;
	int result = 0, count;

	while (~scanf("%c", &input)) {
		if (input == '\n') break;

		if (input == ')') {
			st.pop();
			if (all.top() == ')') {
				result += 1;
			}
			else {
				result += st.size();
			}
			all.push(input);
		}
		else {
			all.push(input);
			st.push(input);
		}
	}

	printf("%d\n", result);

	return 0;
}