#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <deque>
using namespace std;

/*
시간복잡도 : O(n)
공간복잡도 : O(n)
*/

int main()
{
	string input;
	int order_num;
	char order, ch;

	deque<char> left;
	deque<char> right;

	cin >> input;
	scanf("%d", &order_num);

	for (int i = 0; i < input.size(); i++)
		left.push_back(input[i]);

	for (int i = 0; i < order_num; i++) {
		cin >> order;
		switch (order)
		{
		case 'L':
			if (left.empty() == 1) break;
			right.push_front(left.back());
			left.pop_back();
			break;
		case 'D':
			if (right.empty() == 1) break;
			left.push_back(right.front());
			right.pop_front();
			break;
		case 'B':
			if (left.empty() == 1) break;
			left.pop_back();
			break;
		case 'P':
			cin >> ch;
			left.push_back(ch);
			break;
		default:
			break;
		}
	}

	while (left.empty() != 1) {
		printf("%c", left.front());
		left.pop_front();
	}

	while (right.empty() != 1) {
		printf("%c", right.front());
		right.pop_front();
	}	
	
	printf("\n");
	return 0;
}