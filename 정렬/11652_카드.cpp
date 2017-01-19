#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

/*
시간복잡도 : O(nlogn)
공간복잡도 : O(n)
*/

long long arr[1000000];
int cnt[1000000];

int main()
{
	int card_num, n = 0, count = 0, max = 0;
	long long val = 0;

	scanf("%d", &card_num);
	for (int i = 0; i < card_num; i++) {
		scanf("%lld", &arr[i]);		
	}

	sort(arr, arr + card_num);

	count = 1;
	for (int i = 0; i < card_num; i++) {
		if (arr[i] == arr[i + 1]) {
			cnt[i] = count++;
		}
		else {
			cnt[i] = count++;
			count = 1;
		}
		
	}

	for (int i = 0; i < card_num; i++) {
		if (max < cnt[i]) max = cnt[i];
	}

	for (int i = 0; i < card_num; i++) {
		if (max == cnt[i]) {
			printf("%lld\n", arr[i]);
			break;
		}
	}
	return 0;
}