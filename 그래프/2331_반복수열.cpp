#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;

/*
시간복잡도 : O()
공간 복잡도 : O()
*/

int arr[300000];

string calculate(string val, int mulval) 
{
	int intval, result = 0;

	for (int i = 0; i < val.size(); i++) {
		intval = val[i] - '0';
		result += pow(intval, mulval);
	}

	return to_string(result);
	
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);	
#endif 

	int returnval, mul, n, flag = 0, count = 0;
	string num;

	cin >> num >> mul;
	arr[0] = stoi(num);
	
	n = 1;
	while (flag != -1) {
		num = calculate(num, mul);
		returnval = stoi(num);
		count = 0;
		for (int i = 0; i < n; i++) {
			if (returnval == arr[i]) {
				flag = -1;
				break;
			}
			count++;
		}
		arr[n++] = returnval;
	}

	printf("%d\n", count);	

	return 0;
}