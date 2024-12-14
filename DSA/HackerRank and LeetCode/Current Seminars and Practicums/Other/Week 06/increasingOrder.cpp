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
    void dfsFillVec(TreeNode* root, vector<TreeNode*>& vec) {
        if(!root) {
            return;
        }
        dfsFillVec(root->left, vec);
        vec.push_back(root);
        dfsFillVec(root->right, vec);
    }

    TreeNode* increasingBST(TreeNode* root) {
        if(!root ||(!root->left && !root->right)) {
            return root;
        }
        vector<TreeNode*> vec;
        dfsFillVec(root, vec);
        root = vec[0];
        for(int i = 0; i < vec.size() - 1; i++) {
            vec[i]->right = vec[i + 1];
            vec[i]->left = nullptr;
        }
        vec[vec.size() - 1]->left = nullptr;
        vec[vec.size() - 1]->right = nullptr;
        return root;
    }
};
