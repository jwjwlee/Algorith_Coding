
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