#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	string clue, want;
	int result = 0;

	cin >> clue >> want;
	for (int i = 0; i < clue.size(); i++) {
		if(clue.compare(i, want.size(), want) == 0)
			result++;
	}
	printf("%d\n", result);

	return 0;
}