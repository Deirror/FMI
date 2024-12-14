//aka ЛКД -> ляв, корен, десен

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
    void recLKD(TreeNode* root, vector<int>& result) {
        if(!root) {
            return;
        }
        
        recLKD(root->left, result);
        result.push_back(root->val);
        recLKD(root->right, result);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        recLKD(root, result);
        return result;
    }
};
