#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int T;
	string input;
	stack<char> st;

	scanf("%d", &T);
	while(T--) {
		cin >> input;
		bool flag = false;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '(')
				st.push(input[i]);
			else {
				if (st.empty()) {
					flag = true;
					break;
				}
				st.pop();

			}
		}
		if (st.empty() && flag == false) printf("YES\n");
		else printf("NO\n");

		while (!st.empty()) st.pop();
	}

	return 0;
}