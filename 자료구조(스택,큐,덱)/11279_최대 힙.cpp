#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int tree[100001] = { 0 };
int index = 0;

void push(int x)
{
	tree[++index] = x;
	for (int i = index; i > 1; i /= 2) {
		if (tree[i / 2] < tree[i])
			swap(tree[i / 2], tree[i]);
		else
			break;
	}
}

int pop()
{
	if (index == 0) return 0;

	int temp = tree[1];
	swap(tree[index], tree[1]);
	tree[index--] = 0;
	for (int i = 1; i <= index/2;) {
		if (tree[i] > tree[i * 2] && tree[i] > tree[i * 2 + 1]) break;
		else if (tree[i * 2] > tree[i * 2 + 1]) {
			swap(tree[i], tree[i * 2]);
			i *= 2;
		}
		else {
			swap(tree[i], tree[i * 2 + 1]);
			i = i * 2 + 1;
		}
	}

	return temp;
}

int main()
{
	int N, input;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input);
		if (input == 0) printf("%d\n", pop());
		else push(input);
	}

	return 0;
}