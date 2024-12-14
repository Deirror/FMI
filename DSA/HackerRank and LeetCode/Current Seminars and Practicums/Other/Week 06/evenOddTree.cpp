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
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int prev = 0;
        int lastLevel = 0;
        while(q.size()) {
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            bool flagOdd = temp.second % 2 == 0 && temp.first->val % 2 == 0;
            bool flagEven = temp.second % 2 == 1 && temp.first->val % 2 == 1;
            if(flagOdd || flagEven) {
                return false;
            } 

            if(lastLevel < temp.second) {
                prev = 0;
                lastLevel = temp.second; 
            }

            if(prev) {            
            if(temp.second % 2 == 0) {
                if(prev >= temp.first->val) {
                    return false;
                }
            } else {
                if(prev <= temp.first->val) {
                    return false;
                }
            }
            }

            prev = temp.first->val;

            if(temp.first->left) {
                q.push({temp.first->left, temp.second + 1});
            }
            if(temp.first->right) {
                q.push({temp.first->right, temp.second + 1});
            }
        }
        return true;
    }
};
