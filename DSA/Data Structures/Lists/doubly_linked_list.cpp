template <class T>
struct Node {
	T m_Value;
	Node<T>* m_Prev;
	Node<T>* m_Next;

	Node(const T& value, Node<T>* prev = nullptr, Node<T>* next = nullptr)
		: m_Value(value), m_Prev(prev), m_Next(next) {
	}
};

template <class T>
struct LinkedList {
	LinkedList() {
		m_Head = m_Tail = nullptr;
	}

	LinkedList(const LinkedList<T>& other) {
		copy_from(other);
	}

	LinkedList<T>& operator=(const LinkedList<T>& other) {
		if (this != other) {
			free();
			copy_from(other);
		}
		return *this;
	}

	LinkedList(LinkedList<T>&& other) noexcept {
		move_from(std::move(other));
	}

	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept {
		if (this != other) {
			free();
			move_from(std::move(other));
		}
		return *this;
	}

	~LinkedList() {
		free(m_Head);
	}

	void push_front(const T& value) {
		Node<T>* node = new Node<T>(value, nullptr, m_Head);
		m_Head = node;

		if (!m_Tail) {
			m_Tail = node;
		}
	}

	void insert(size_t idx, const T& value) {
		if (!idx) {
			push_front(value);
		}
		else if (!m_Head && !m_Tail) {
			return;
		}
		else {
			Node<T>* curr = m_Head;

			for (size_t i = 0; i < idx; i++) {
				curr = curr->m_Next;
				if (!curr) {
					if (i + 1 == idx) {
						push_back(value);
					}
					return;
				}
			}

			Node<T>* node = new Node<T>(value, curr->m_Prev, curr);
			curr->m_Prev->m_Next = node;
			curr->m_Prev = node;
		}
	}

	void push_back(const T& value) {
		Node<T>* node = new Node<T>(value, m_Tail);
		if (!m_Head && !m_Tail) {
			m_Tail = m_Head = node;
		}
		else {
			m_Tail->m_Next = node;
			m_Tail = node;
		}
	}

	void pop_front() {
		if (!m_Head || !m_Tail) {
			return;
		}

		Node<T>* temp = m_Head;
		m_Head = m_Head->m_Next;
		delete temp;

		if (!m_Head) {
			m_Tail = nullptr;
		} else {
			m_Head->m_Prev = nullptr;
		}
	}

	void remove(size_t idx) {
		if (!idx) {
			pop_front();
		}
		else if (!m_Head && !m_Tail) {
			return;
		}
		else {
			Node<T>* curr = m_Head;
			for (size_t i = 0; i < idx; i++) {
				curr = curr->m_Next;
				if (!curr) {
					return;
				}
			}

			if (!curr->m_Next) {
				pop_back();
			}
			else {
				Node<T>* prev = curr->m_Prev;
				Node<T>* next = curr->m_Next;

				prev->m_Next = next;
				next->m_Prev = prev;

		  		delete curr;
		    }
		}
	}

	void pop_back() {
		if (!m_Head || !m_Tail) {
			return;
		}

		Node<T>* curr = m_Head;

		if (!curr->m_Next) {
			pop_front();
			return;
		}

		while (curr->m_Next != m_Tail) {
			curr = curr->m_Next;
		}

		delete m_Tail;
		m_Tail = curr;
		curr->m_Next = nullptr;
	}

private:
	Node<T>* m_Head;
	Node<T>* m_Tail;

	void copy_from(const LinkedList<T>& other) {
		Node<T>* curr = other.m_Head;
		while (curr) {
			push_back(curr->m_Value);
			curr = curr->m_Next;
		}
	}

	void move_from(LinkedList<T>&& other) {
		m_Head = other.m_Head;
		m_Tail = other.m_Tail;
		other.m_Head = other.m_Tail = nullptr;
	}

	void free(Node<T>* head) {
		if (head == m_Tail) {
			delete head;
			m_Head = m_Tail = nullptr;
			return;
		}

		free(head->m_Next);
		delete head;
	}
};
