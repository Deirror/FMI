/*
 -> Change the values of each node, so that the new value is equl to the original value 
    plus the sum of the nodes with higher width(from most left to most right)
*/

/*
 *
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
    int findMostLeft(TreeNode* subroot, int len = 0) {
        if(!subroot) {
            return len;
        }
        return max(findMostLeft(subroot->left, len + 1), findMostLeft(subroot->right, len - 1));
    }   

    int findMostRight(TreeNode* subroot, int len = 0) {
        if(!subroot) {
            return len;
        }
        return max(findMostRight(subroot->left, len - 1), findMostRight(subroot->right, len + 1));
    }   

    void fillPathsSum(TreeNode* root, int pathIdx, vector<int>& paths) {
        if(!root) {
            return;
        }
        fillPathsSum(root->left, pathIdx - 1, paths);
        paths[pathIdx] += root->val;
        fillPathsSum(root->right, pathIdx + 1, paths);
    }

    int getPathsSum(int pathIdx, vector<int>& paths) {
        static vector<int> cachedPathsSum(paths.size() + 1, -1);
        if(pathIdx >= paths.size()) {
            return 0;
        }
        if(cachedPathsSum[pathIdx] == -1) {
            for(int i = pathIdx; i < paths.size(); i++) {
                cachedPathsSum[pathIdx] += paths[i];
            }
        }
        return cachedPathsSum[pathIdx];
    }

    void changeBSTValues(TreeNode* root, int pathIdx, vector<int>& paths) {
        if(!root) {
            return;
        }
        root->val = root->val + getPathsSum(pathIdx + 1, paths);
        fillPathsSum(root->left, pathIdx - 1, paths);
        fillPathsSum(root->right, pathIdx + 1, paths);
    }

    TreeNode* convertBST(TreeNode* root) {
        int lenMostLeft = findMostLeft(root->left);
        int lenMostRight = findMostRight(root->right);
        int size = lenMostLeft + lenMostRight + 1;
        vector<int> paths(size, 0);
        fillPathsSum(root, lenMostLeft, paths);
        changeBSTValues(root, lenMostLeft, paths);
        return root;
    }
};
