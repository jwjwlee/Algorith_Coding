#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <time.h>
using namespace std;

void FixHeap(int, int, int);			//MaxHeap의 partial order를 만족시키기 위한 downheap하는 함수
void ConstructHeap(int, int);			//Tree의 밑에서 부터 left, right subtree로 나눠서 재귀적으로 fixheap하여 heap을 만드는 함수
void Heapsort(int, int);				//Heapsort를 하는 함수
void AcceleratedHeapSort(int, int);		//AcceleratedHeapSort하는 함수
int Promote(int, int, int);				//현재 트리 높이의 h/2 까지 downheap하는 함수
void FixHeapFast(int, int, int, int);	//FixHeap보다 좀 더 빠른 FixHeapFast 함수
void bubbleUpHeap(int, int, int);		//잘 내려왔는지 검사 후, 잘못 내려왔을 시 다시 upheap하는 함수

int tree[10000001], Acceltree[10000001];
int HeapsortANS, AccelHeapANS = 0;
bool flag;

int main()
{
	int caseNum, N, size, HeapsortM1, AccelHeapsortM2;
	clock_t start_time, end_time;
	double Heapsort_Time, AccelHeapsort_Time;

	scanf("%d", &caseNum);
	while (caseNum--) {
		flag = false;
		AccelHeapANS = 0;
		scanf("%d", &N);	//정렬 정수 입력받기
		for (size = 1; size <= N; size++) {
			scanf("%d", &tree[size]);
		}
		scanf("%d %d", &HeapsortM1, &AccelHeapsortM2);	//M1. M2 입력받기

		ConstructHeap(1, N);			//Heap을 만든다
		for (int i = 1; i <= N; i++) {	//AcceleratedHeapSort를 위해 똑같은 트리를 하나 더 만든다
			Acceltree[i] = tree[i];
		}

		start_time = clock();
		Heapsort(N, HeapsortM1);		//Heapsort 함수 호출		
		end_time = clock();
		Heapsort_Time = (double)(end_time - start_time) / CLOCKS_PER_SEC;	//시간측정 결과

		start_time = clock();
		AcceleratedHeapSort(N, AccelHeapsortM2);	//AcceleratedHeapSort 함수 호출
		end_time = clock();
		AccelHeapsort_Time = (double)(end_time - start_time) / CLOCKS_PER_SEC;		//시간측정 결과

		printf("%d %d\n", HeapsortANS, AccelHeapANS);						//정답 출력
		printf("%0.3f %0.3f\n", AccelHeapsort_Time, Heapsort_Time);			//시간 출력

	}
	return 0;
}


void ConstructHeap(int top, int bottom)
{
	if (2 * top > bottom) return;				//Leaf이면 이미 Heap이므로 return
	else {
		ConstructHeap(2 * top, bottom);			//left child subtree	
		ConstructHeap(2 * top + 1, bottom);		//right child subtree
		int K = tree[top];
		FixHeap(bottom, top, K);				//Heap 재구성하는 함수 호출
	}
}



void Heapsort(int size, int HeapsortM1)
{
	for (int i = size; i > size - HeapsortM1; i--) {	//M1번째 만큼 heapsort수행
		HeapsortANS = -1;
		int K = tree[i];			//마지막노드 저장
		FixHeap(i - 1, 1, K);		//Heap 재구성하는 함수 호출
	}
	return;
}

void FixHeap(int size, int root, int K)
{
	if (2 * root > size) 	//leaf노드 일때
		tree[root] = K;
	else {
		//더 큰 subheap을 찾는다
		int largerSubHeap;
		if (tree[2 * root] == size) largerSubHeap = 2 * root;
		else if (tree[2 * root + 1] > tree[2 * root])
			largerSubHeap = 2 * root + 1;
		else
			largerSubHeap = 2 * root;

		//K값과 비교하여 맞는 자리로 간다
		if (K > tree[largerSubHeap])
			tree[root] = K;
		else {
			tree[root] = tree[largerSubHeap];
			HeapsortANS = log2(root);			//마지막으로 fixheap호출한 노드의 깊이 구하기 위해
			FixHeap(size, largerSubHeap, K);	//FixHeap재귀 호출
		}
	}
	return;
}




void AcceleratedHeapSort(int size, int AccelHeapsortM2)
{
	for (int i = size; i > size - AccelHeapsortM2; i--) {	//M2번째 만큼 heapsort수행
		int K = Acceltree[i];				//마지막노드 저장	
		int Height = log2(i);				//트리의 높이를 구함

		if (i == size - AccelHeapsortM2 + 1) {		//M2번째일 때 flag를 true로
			flag = true;
		}
		FixHeapFast(i - 1, K, 1, Height);	//Heap 재구성하는 FixHeapFast함수 호출
	}
}

void FixHeapFast(int size, int K, int vacant, int h)
{
	if (2 * vacant > size) {		//leaf노드 일때
		Acceltree[vacant] = K;
		return;
	}

	if (h == 0) return;
	else {
		int hStop = h / 2;							//트리 높이의 반만큼 내려가므로 멈출 높이를 구함(홀수 일 경우를 고려해 h + 1)

		int vacStop = Promote(hStop, vacant, h);	//Promote를 통해 vacant가 멈춘 노드를 받아옴
		int vacParent = vacStop / 2;				//잘 내려왔는지 비교를 위해 멈춘 노드의 부모 노드를 구함

		if (Acceltree[vacParent] < K) {				//K와 비교결과 잘못내려왔을 경우  

			if (flag == true) {
				AccelHeapANS = Acceltree[vacParent];		//M2번째 큰 수를 찾을 때 처음으로 bubbleupheap을 하는 노드의 원래 값 저장
				flag = false;
			}

			Acceltree[vacStop] = Acceltree[vacParent];		//vacStop에 부모노드 였던 값을 넣어줌	
			bubbleUpHeap(vacant, K, vacParent);				//다시 올라가기 위한 bubbleupheap수행
		}
		else                                                //잘 내려왔을 경우
			FixHeapFast(size, K, vacStop, hStop);			//다시 promote 진행을 위해 FixHeapFasat 재귀호출
	}
}

int Promote(int hStop, int vacant, int h)
{
	int vacStop;		//멈출 곳의 노드(index)

	if (h <= hStop)
		vacStop = vacant;
	else if (Acceltree[vacant * 2] < Acceltree[vacant * 2 + 1]) {		//rightchild가 더 클 경우
		Acceltree[vacant] = Acceltree[vacant * 2 + 1];
		vacStop = Promote(hStop, 2 * vacant + 1, h - 1);				//Promote계속 진행
	}
	else {																//leftchild가 더 클 경우
		Acceltree[vacant] = Acceltree[vacant * 2];
		vacStop = Promote(hStop, 2 * vacant, h - 1);					//Promote계속 진행
	}

	return vacStop;
}

void bubbleUpHeap(int root, int K, int vacant)
{
	if (vacant == root)					//이전 높이의 반만큼 왔을 때 더 이상 확인할 필요 없으므로
		Acceltree[vacant] = K;
	else {
		int parent = vacant / 2;
		if (K < Acceltree[parent])		//부모가 더 클 경우
			Acceltree[vacant] = K;
		else {							//부모가 더 작을 경우	 
			Acceltree[vacant] = Acceltree[parent];
			bubbleUpHeap(root, K, parent);		//더 올라가야하므로 bubbleUpHeap 재귀
		}
	}
}
