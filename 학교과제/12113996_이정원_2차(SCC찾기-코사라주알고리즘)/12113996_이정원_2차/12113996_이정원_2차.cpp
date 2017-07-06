#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <fstream>
#include <time.h>
using namespace std;

struct infomation				//�л��� ������ ������ struct
{
	string name, age;
	int id;			
};

void DFS(int);				//DFS�� �����ϴ� �Լ�
void rev_DFS(int);			//������ �׷����� ���� DFS�� �����ϴ� �Լ�	
void Union(int, int);		//���� �׷쳢�� ���� �Լ�(Union Find �ڷᱸ��)
int Find(int);				//�ڽ��� ��ǥ ��ȣ�� ã�� �Լ�(Union Find �ڷᱸ��)

int net[2001][2001] = { 0 };		//�������
int rev_net[2001][2001] = { 0 };	//������ �׷����� ���� �������
int group[2001] = { 0 };			//�׷��� ���³��� �迭
bool visit[2001];					//visit�� ���θ� ��Ÿ���� �迭
stack<int> st;						//������ ���� ����
int num;							//�л� ��


int main()
{

	int M, N, S;		//������ �� �й�
	char Op;			//����
	bool end = true;
	string fileName, studentNum, info;
	infomation student[2001];
	clock_t start_time, end_time;

	start_time = clock();	//���۽ð�

	//���� �̸� �Է�
	printf("�Է������� �̸��� �Է��ϼ��� : \n");	
	cin >> fileName;			

	//�ش� ���� �̸��� ���� �о ����
	ifstream inputFile(fileName);
	
	getline(inputFile, studentNum);		//�л� �� �о����
	num = stoi(studentNum);				//�л� �� ����

	int index = 0;
	while (!inputFile.eof()) {
		getline(inputFile, info);					//�л� ���� �о����
		if (info.length() == 0) continue;			//�������Ʈ.txt ������ ���ο� �����־ �߰�
		student[index].name = info.substr(0, 6);	//�л� �̸� ����
		student[index].age = info.substr(7);		//�л� ���� ����
		student[index].id = index + 1000;			//�л� id �ο�
		index++;
	}
	inputFile.close();

	for (int i = 0; i < num; i++) group[i] = i;		//��ǥ��ȣ�� �ڱ��ڽ����� �ʱ�ȭ

	while (end) {
		
		getchar();
		scanf("%c", &Op);
		getchar();

		switch (Op)
		{

		/*����ó �����߰��� ���*/
		case 'I':							

			scanf("%d %d", &M, &N);
			net[M - 1000][N - 1000] = 1;		//�׷����� ���� �߰�
			rev_net[N - 1000][M - 1000] = 1;	//������ �׷����� ���� �߰�

			for (int i = 0; i < num; i++) visit[i] = false;		//visit�迭 �ʱ�ȭ

			for (int i = 0; i < num; i++) {			//��� ������ ���� DFS����
				if (visit[i]) continue;
				DFS(i);
			}

			for (int i = 0; i < num; i++) visit[i] = false;		//visit�迭 �ʱ�ȭ

			//���ÿ��� ������ �ϳ��� ���鼭 �ش� ������ 
			//�������� ������ �׷����� ���� DFS����
			while (!st.empty()) {
				int top = st.top();
				st.pop();
				if (visit[top]) continue;

				rev_DFS(top);
			}

			break;
				
		/*�׷� ��ǥ Ȯ�� ������ ���*/
		case 'O':				
			scanf("%d", &S);
			printf("%d\n", group[S - 1000] + 1000);		//���� ���
			break;

		/*���α׷� ����*/
		case 'Q':					
			end = false;
			break;
		}
	}
	
	end_time = clock();		//������ �ð�
	printf("%0.3f\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);		//�ɸ� �ð� ���

	return 0;
}


void DFS(int x)
{
	visit[x] = true;

	for (int i = 0; i < num; i++) {
		if (net[x][i] == 1 && !visit[i]) {		//edge�� �ְ� �̹湮���� �̸�
			DFS(i);								//DFS��� ȣ��
		}
	}
	st.push(x);		//DFS�� ������ ������ �ش� ������ ���ÿ� ����
}

void rev_DFS(int x)
{
	visit[x] = true;

	for (int i = 0; i < num; i++) {
		if (rev_net[x][i] == 1 && !visit[i]) {		//edge�� �ְ� �̹湮���� �̸�
			Union(x, i);							//���� �׷����� ����
			rev_DFS(i);								//DFS��� ȣ��
		}
	}
}


int Find(int x) 
{
	if (x == group[x]) return x;			//�ڱ�� ��ǥ��ȣ�� ������ ����
	else return group[x] = Find(group[x]);	//�ٸ��� ���ȣ��
}

void Union(int x, int y)
{
	x = Find(x);	//x�� �׷� ��ǥ��ȣ�� ã�´�
	y = Find(y);	//y�� �׷� ��ǥ��ȣ�� ã�´�

	//�� ���� �й��� ��ǥ ��ȣ�� ����
	if (x == y) return;
	else if (x < y) group[y] = x;
	else group[x] = y;
}
