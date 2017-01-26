#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

/*
�ð����⵵ : O(nlogn)
�������⵵ : O(n)
*/


int main()
{
	string input;
	string arr[1000];
	cin >> input;

	for (int i = 0; i < input.size(); i++) {
		arr[i] = input.substr(i, input.size());
	}

	sort(arr, arr + input.size());
	
	for (int i = 0; i < input.size(); i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}