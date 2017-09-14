
struct stack
{
	int data[10000];
	int size = 0;

	void push(int val) {
		data[size++] = val;
	}

	int pop() {
		if (size == 0) return -1;
		else return data[size--];
	}

	bool empty() {
		if (size == 0) return true;
		else return false;
	}

	int top() {
		if (size == 0) return -1;
		return data[size - 1];
	}
};