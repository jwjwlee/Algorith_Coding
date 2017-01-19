#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	string inputcolor;
	long long result = 0;

	string resistance[10] = { "black", "brown", "red", "orange", "yellow", "green",
								"blue", "violet", "grey", "white" };
	
	cin >> inputcolor;
	for (int i = 0; i < 10; i++) {
		if (resistance[i] == inputcolor)
			result = 10 * i;
	}

	cin >> inputcolor;
	for (int i = 0; i < 10; i++) {
		if (resistance[i] == inputcolor)
			result += i;
	}
	
	cin >> inputcolor;
	for (int i = 0; i < 10; i++) {
		if (resistance[i] == inputcolor)
			result *= pow(10, i);
	}

	printf("%lld\n", result);

	return 0;
}