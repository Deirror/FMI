#include <list>
class Stack {
public:
	void push(int value) {
		data.push_back(value);
	} 

	void pop() {
		data.pop_back();
	}

	int peek() const {
		return data.front();
	}

	bool isEmpty() const {
		return data.size() == 0;
	}
private:
	std::list<int> data;
};
