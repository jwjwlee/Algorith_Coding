#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
#include <math.h>
using namespace std;

/*
시간복잡도: O(n)
공간복잡도: O(n)
*/
int main()
{
	int ival, notation, result = 0;
	char cval = NULL;
	stack<int> st;

	while (~scanf("%c", &cval)) {
		if (cval == ' ') break;
		if (47 < cval && cval < 58) {
			ival = cval - 48;
			st.push(ival);
		}
		else {
			ival = cval - 55;
			st.push(ival);
		}
	}

	scanf("%d", &notation);

	int size = st.size();
	for (int i = 0; i < size; i++) {
		result += st.top() * pow(notation, i);
		st.pop();
	}

	printf("%d\n", result);

	return 0;
}