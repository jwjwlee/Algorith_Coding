#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;

long long calculate(long long val, long long num)
{
	long long count = 0, temp = num;
	while (temp <= val) {
		count += val / temp;
		temp *= num;
	}
	
	return count;
}

int main()
{
	long long n, m, cnt2, cnt5;

	scanf("%lld %lld", &n, &m);

	cnt2 = calculate(n, 2) - calculate(m, 2) - calculate(n - m, 2);
	cnt5 = calculate(n, 5) - calculate(m, 5) - calculate(n - m, 5);

	if(cnt2 > cnt5)
		printf("%lld\n", cnt5);
	else
		printf("%lld\n", cnt2);

	return 0;
}
