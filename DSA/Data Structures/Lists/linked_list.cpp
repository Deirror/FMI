template <class T>
struct Node {
	T m_Value;
	Node<T>* m_Next = nullptr;

	Node(const T& value) {
		this->m_Value = value;
		this->m_Next = nullptr;
	}

	Node(const T& value, Node<T>* next) {
		this->m_Value = value;
		this->m_Next = next;
	}
};

template <class T>
struct LinkedList {
	LinkedList() = default;

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
		Node<T>* node = new Node<T>(value);
		node->m_Next = m_Head;
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
			Node<T>* prev = nullptr;
			Node<T>* curr = m_Head;

			for (size_t i = 0; i < idx; i++) {
				prev = curr;
				curr = curr->m_Next;
				if (!curr) {
					if (i + 1 == idx) {
						push_back(value);
					}
					return;
				}
			}

			Node<T>* node = new Node<T>(value, curr);
			prev->m_Next = node;

			if (prev == m_Tail) {
				m_Tail = node;
			}
		}
	}

	void push_back(const T& value) {
		Node<T>* node = new Node<T>(value);
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
			Node<T>* prev = nullptr;
			Node<T>* curr = m_Head;

			for (size_t i = 0; i < idx; i++) {
				prev = curr;
				curr = curr->m_Next;
				if (!curr) {
					return;
				}
			}

			prev->m_Next = curr->m_Next;

			if (curr == m_Tail) {
				m_Tail = prev;
			}

			delete curr;
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
	Node<T>* m_Head = nullptr;
	Node<T>* m_Tail = nullptr;

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
