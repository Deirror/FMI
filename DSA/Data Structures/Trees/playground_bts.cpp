#include <iostream>
#include <queue>
#include <stack>

struct TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr) 
		: data(data), left(left), right(right) {}
};

class BTS {
	TreeNode* root;
	void _inorderTraversal(TreeNode* root) const {
		if (!root) {
			return;
		}

		_inorderTraversal(root->left);
		std::cout << root->data;
		_inorderTraversal(root->right);
	}

	TreeNode** findMin(TreeNode** subroot) {
		while ((*subroot)->left) {
			subroot = &(*subroot)->left;
		}
		return subroot;
	}
public:
	BTS() : root(nullptr) {}

	bool contains(int target) const {
		TreeNode* curr = root;
		while (curr) {
			if (curr->data < target) {
				curr = curr->right;
			}
			else if (target < curr->data) {
				curr = curr->left;
			}
			else {
				return true;
			}
		}
		return false;
	}

	void insert(int data) {
		TreeNode** curr = &root;
		while (*curr) {
			if ((*curr)->data < data) {
				curr = &(*curr)->right;
			}
			else if (data < (*curr)->data) {
				curr = &(*curr)->left;
			}
		}
		*curr = new TreeNode(data); 
	}

	//recursive dfs
	void inorderTraversal() const {
		_inorderTraversal(this->root);
	}

	//iterative dfs
	void iterativeDFS() const {
		std::stack<TreeNode*> st;
		TreeNode* curr = root;
		while (curr || st.size()) {
			while (curr) {
				st.push(curr);
				curr = curr->left;
			}
			curr = st.top();
			st.pop();
			std::cout << curr->data << " ";
			curr = curr->right;
		}
		
	}

	void levelOrderTraversal() const {
		TreeNode* curr = root;
		std::queue<TreeNode*> q;
		q.push(root);
		while (q.size()) {
			TreeNode* temp = q.front();
			q.pop();
			std::cout << temp->data << ' ';
			if (temp->left) {
				q.push(temp->left);
			}
			if (temp->right) {
				q.push(temp->right);
			}
		}
	}

	void remove(int val) {
		TreeNode** curr = &root;

		while (*curr) {
			if ((*curr)->data < val) {
				curr = &(*curr)->right;
			}
			else if (val < (*curr)->data) {
				curr = &(*curr)->left;
			}
			else {
				break;
			}
		}

		if (*curr == nullptr) {
			return;
		}

		TreeNode* to_remove = *curr;

		if (!to_remove->left && !to_remove->right) {
			*curr = nullptr;
		}
		else if (to_remove->left && !to_remove->right) {
			*curr = to_remove->left;
		}
		else if (!to_remove->left && to_remove->right) {
			*curr = to_remove->right;
		}
		else {
			TreeNode** minInRightBST = findMin(&to_remove->right);

			*curr = *minInRightBST;
			*minInRightBST = (*minInRightBST)->right;

			(*curr)->left = to_remove->left;
			(*curr)->right = to_remove->right;

		}
		delete to_remove;
	}

	void postorderBFS() const {
		std::deque<std::pair<TreeNode*, int>> dq;
		dq.push_back({ root, 0 });
		while (dq.size()) {
			std::pair<TreeNode*, int> temp;
			if (dq.back().second == dq.front().second && dq.back().second % 2 == 0) {
				temp = dq.back();
			}
			else if (dq.back().second == dq.front().second && dq.back().second % 2 == 1) {
				temp = dq.front();
			} 
			else
			{
				temp = (dq.back().second < dq.front().second) ? dq.back() : dq.front();
			}

			if (temp.second % 2 == 0) {
				dq.pop_back();
				std::cout << temp.first->data << ' ';
				if (temp.first->right) {
					dq.push_front({ temp.first->right , temp.second + 1});
				} 
				if (temp.first->left) {
					dq.push_front({ temp.first->left , temp.second + 1 });
				}
			}
			else {
				dq.pop_front();
				std::cout << temp.first->data << ' ';
				if (temp.first->left) {
					dq.push_back({ temp.first->left , temp.second + 1 });
				}
				if (temp.first->right) {
					dq.push_back({ temp.first->right , temp.second + 1 });
				}
			}
		}
	}

};

int main() {
	BTS bts;
	bts.insert(1);
	bts.insert(2);
	bts.insert(10);
	bts.insert(11);
	bts.insert(5);
	bts.insert(4);
	bts.insert(0);
	bts.insert(-1);

	bts.remove(0);
	bts.remove(1);

	bts.iterativeDFS();
	//bts.levelOrderTraversal();

	return 0;
}
