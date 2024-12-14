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
    int maxDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<vector<int>> levels(maxDepth(root));
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while(q.size()) {
            pair<int, TreeNode*> temp = q.front();
            q.pop();
            levels[temp.first].push_back(temp.second->val);
            if(temp.second->left) {
                q.push({temp.first + 1, temp.second->left});
            }
            if(temp.second->right) {
                q.push({temp.first + 1, temp.second->right});
            }
        }
        return levels;
    }
};
