#include <iostream>
#include <string>
using namespace std;

struct queue
{
	int data[10000];
	int head = 0, tail = 0;

	void push(int val) {
		data[tail++] = val;
	}

	int size() {
		return tail - head;
	}

	bool empty() {
		if (tail == head) return true;
		else return false;
	}

	int pop() {
		if (empty()) return -1;
		else return data[head++];
	}

	int front() {
		if (empty()) return -1;
		return data[head];
	}

	int back() {
		if (empty()) return -1;
		return data[tail - 1];
	}
};

int main() {
	freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	queue q;

	while (n--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (cmd == "pop") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (cmd == "size") {
			cout << q.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << q.empty() << '\n';
		}
		else if (cmd == "front") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
			}
		}
		else if (cmd == "back") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.back() << '\n';
			}
		}
	}

	return 0;
}
