#include <list>

class Queue {
public:
	void enqueue(int value) {
		data.push_back(value);
	}

	void dequeue() {
		data.pop_front();
	}

	int front() const {
		return data.front();
	}

	bool isEmpty() const {
		return data.size() == 0;
	}
private:
	std::list<int> data;
};
