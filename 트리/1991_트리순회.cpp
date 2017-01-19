#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct MyStruct
{
	char Left, Right;
}btree[27];


void preorder(char parent)
{
	if (parent == '.') return;
	printf("%c", parent);
	preorder(btree[parent - 'A'].Left);
	preorder(btree[parent - 'A'].Right);
}

void inorder(char parent)
{
	if (parent == '.') return;
	inorder(btree[parent - 'A'].Left);
	printf("%c", parent);
	inorder(btree[parent - 'A'].Right);
}

void postorder(char parent)
{
	if (parent == '.') return;
	postorder(btree[parent - 'A'].Left);
	postorder(btree[parent - 'A'].Right);
	printf("%c", parent);
}

int main()
{
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif 

	int N;
	char val, Lval, Rval;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> val >> Lval >> Rval;
		btree[val - 'A'].Left = Lval;
		btree[val - 'A'].Right = Rval;	
	}

	preorder('A');
	printf("\n");
	inorder('A');	
	printf("\n");
	postorder('A');
	printf("\n");

	return 0;
}
