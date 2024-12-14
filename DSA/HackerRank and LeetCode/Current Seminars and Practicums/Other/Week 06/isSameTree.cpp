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
    void recCheckTrees(TreeNode* p, TreeNode* q, bool& flag) {
        if(!p && !q) {
            return;
        } else if(!p || !q) {
            flag = false;
            return;
        }

        recCheckTrees(p->left, q->left, flag);
        if(!flag) {
            return;
        }
        flag = (p->val == q->val);
        recCheckTrees(p->right, q->right, flag);
         if(!flag) {
            return;
        }
        flag = (p->val == q->val);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag = true;
        recCheckTrees(p, q, flag);
        return flag;
    }
};
