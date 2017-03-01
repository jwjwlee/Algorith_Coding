#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int N;
	string input;
	stack<char> st;

	scanf("%d", &N);
	bool flagA = false;
	bool flagB = false;
	int result = 0;
	while (N--) {
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			if (st.empty()) st.push(input[i]);
			else {
				if (st.top() == input[i]) st.pop();
				else st.push(input[i]);
			}
		}
		if (st.empty()) result++;
		while (!st.empty()) st.pop();
	}
	printf("%d\n", result);

	return 0;
}