/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int dfs(Node* node, int level) {
        if(!node->children.size()) {
            return level;
        }
        int maxLevel = level;
        for(int i = 0; i < node->children.size(); i++) {
            maxLevel = max(maxLevel, dfs(node->children[i], level + 1));
        }
        return maxLevel;
    }

    int maxDepth(Node* root) {
        if(!root) return 0;
        return dfs(root, 1);
    }
};
