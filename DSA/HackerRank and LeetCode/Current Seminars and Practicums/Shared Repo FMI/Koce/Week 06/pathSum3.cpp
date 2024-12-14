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
    void recSumNodesVals(TreeNode* root, long long& currSum, int& counter,long long targetSum) {
        if(!root) {
            return;
        }
        currSum += root->val;
        if(currSum == targetSum) {
            counter++;
        }
        recSumNodesVals(root->left, currSum, counter,targetSum);
        recSumNodesVals(root->right,currSum, counter,targetSum);      
        currSum -= root->val;
    }

    void recCheck(TreeNode* root, int& counter, long long targetSum) {
        if(!root) {
            return;
        }
        long long currSum = root->val;
        if(currSum == targetSum) {
            counter++;
        } 
        recSumNodesVals(root->left, currSum, counter, targetSum);
        recSumNodesVals(root->right, currSum, counter,targetSum);     
        recCheck(root->left, counter, targetSum);
        recCheck(root->right, counter, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int counter = 0;
        recCheck(root, counter, targetSum);
        return counter;
    }
};
