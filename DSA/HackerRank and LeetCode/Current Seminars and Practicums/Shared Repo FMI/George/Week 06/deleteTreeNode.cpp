/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode** findMin(TreeNode** subroot) {
		while ((*subroot)->left) {
			subroot = &(*subroot)->left;
		}
		return subroot;
	}

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode** curr = &root;

		while (*curr) {
			if ((*curr)->val < key) {
				curr = &(*curr)->right;
			}
			else if (key < (*curr)->val) {
				curr = &(*curr)->left;
			}
			else {
				break;
			}
		}

		if (*curr == nullptr) {
			return root;
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
        return root;
    }
};
