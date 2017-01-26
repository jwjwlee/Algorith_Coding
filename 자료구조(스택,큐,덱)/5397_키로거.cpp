#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif 

	int case_num;	
	char input;
	deque<char> deq1;
	deque<char> deq2;

	scanf("%d", &case_num);
	input = getchar();
	for (int c = 0; c < case_num; c++) {
		while (~scanf("%c", &input)) {
			if (input == '\n') break;
			
			if (input == '<') {
				if (deq1.empty() != 1) {
					deq2.push_front(deq1.back());
					deq1.pop_back();
				}
			}
			else if (input == '>') {
				if (deq2.empty() != 1) {
					deq1.push_back(deq2.front());
					deq2.pop_front();
				}
			}
			else if (input == '-') {
				if(deq1.empty() != 1)
				deq1.pop_back();
			}
			else {
				deq1.push_back(input);
			}
		}

		while(deq1.empty() != 1) {
			printf("%c", deq1.front());
			deq1.pop_front();
		}
		while (deq2.empty() != 1) {
			printf("%c", deq2.front());
			deq2.pop_front();	
		}
		printf("\n");
	}

	return 0;
}