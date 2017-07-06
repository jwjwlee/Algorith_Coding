#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <fstream>
#include <time.h>
using namespace std;

struct infomation				//학생의 정보를 저장할 struct
{
	string name, age;
	int id;			
};

void DFS(int);				//DFS를 수행하는 함수
void rev_DFS(int);			//역방향 그래프에 대해 DFS를 수행하는 함수	
void Union(int, int);		//같은 그룹끼리 묶는 함수(Union Find 자료구조)
int Find(int);				//자신의 대표 번호를 찾는 함수(Union Find 자료구조)

int net[2001][2001] = { 0 };		//인접행렬
int rev_net[2001][2001] = { 0 };	//역방향 그래프를 위한 인접행렬
int group[2001] = { 0 };			//그룹을 나태내는 배열
bool visit[2001];					//visit의 여부를 나타내는 배열
stack<int> st;						//정점을 넣을 스택
int num;							//학생 수


int main()
{

	int M, N, S;		//질의의 각 학번
	char Op;			//질의
	bool end = true;
	string fileName, studentNum, info;
	infomation student[2001];
	clock_t start_time, end_time;

	start_time = clock();	//시작시간

	//파일 이름 입력
	printf("입력파일의 이름을 입력하세요 : \n");	
	cin >> fileName;			

	//해당 파일 이름의 파일 읽어서 저장
	ifstream inputFile(fileName);
	
	getline(inputFile, studentNum);		//학생 수 읽어오기
	num = stoi(studentNum);				//학생 수 저장

	int index = 0;
	while (!inputFile.eof()) {
		getline(inputFile, info);					//학생 정보 읽어오기
		if (info.length() == 0) continue;			//멤버리스트.txt 마지막 라인에 공백있어서 추가
		student[index].name = info.substr(0, 6);	//학생 이름 저장
		student[index].age = info.substr(7);		//학생 나이 저장
		student[index].id = index + 1000;			//학생 id 부여
		index++;
	}
	inputFile.close();

	for (int i = 0; i < num; i++) group[i] = i;		//대표번호를 자기자신으로 초기화

	while (end) {
		
		getchar();
		scanf("%c", &Op);
		getchar();

		switch (Op)
		{

		/*연락처 정보추가인 경우*/
		case 'I':							

			scanf("%d %d", &M, &N);
			net[M - 1000][N - 1000] = 1;		//그래프에 간선 추가
			rev_net[N - 1000][M - 1000] = 1;	//역방향 그래프에 간선 추가

			for (int i = 0; i < num; i++) visit[i] = false;		//visit배열 초기화

			for (int i = 0; i < num; i++) {			//모든 정점에 대해 DFS수행
				if (visit[i]) continue;
				DFS(i);
			}

			for (int i = 0; i < num; i++) visit[i] = false;		//visit배열 초기화

			//스택에서 정점을 하나씩 빼면서 해당 정점을 
			//시작으로 역방향 그래프에 대해 DFS수행
			while (!st.empty()) {
				int top = st.top();
				st.pop();
				if (visit[top]) continue;

				rev_DFS(top);
			}

			break;
				
		/*그룹 대표 확인 질의인 경우*/
		case 'O':				
			scanf("%d", &S);
			printf("%d\n", group[S - 1000] + 1000);		//정답 출력
			break;

		/*프로그램 종료*/
		case 'Q':					
			end = false;
			break;
		}
	}
	
	end_time = clock();		//끝나는 시간
	printf("%0.3f\n", (double)(end_time - start_time) / CLOCKS_PER_SEC);		//걸린 시간 출력

	return 0;
}


void DFS(int x)
{
	visit[x] = true;

	for (int i = 0; i < num; i++) {
		if (net[x][i] == 1 && !visit[i]) {		//edge가 있고 미방문상태 이면
			DFS(i);								//DFS재귀 호출
		}
	}
	st.push(x);		//DFS가 끝나는 순으로 해당 정점을 스택에 삽입
}

void rev_DFS(int x)
{
	visit[x] = true;

	for (int i = 0; i < num; i++) {
		if (rev_net[x][i] == 1 && !visit[i]) {		//edge가 있고 미방문상태 이면
			Union(x, i);							//같은 그룹으로 묶고
			rev_DFS(i);								//DFS재귀 호출
		}
	}
}


int Find(int x) 
{
	if (x == group[x]) return x;			//자기와 대표번호가 같으면 리턴
	else return group[x] = Find(group[x]);	//다르면 재귀호출
}

void Union(int x, int y)
{
	x = Find(x);	//x의 그룹 대표번호를 찾는다
	y = Find(y);	//y의 그룹 대표번호를 찾는다

	//더 작은 학번을 대표 번호로 지정
	if (x == y) return;
	else if (x < y) group[y] = x;
	else group[x] = y;
}
