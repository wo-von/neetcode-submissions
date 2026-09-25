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
private:
    int counter = 0;

public:
    void goodNodes_dfs(TreeNode* node, int max) {
        if (node->val >= max) {
            counter++;
        }
        if (node->left) {
            goodNodes_dfs(node->left, std::max(max, node->left->val));
        }
        if (node->right) {
            goodNodes_dfs(node->right, std::max(max, node->right->val));
        }
    }
    
    int goodNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        goodNodes_dfs(root, root->val);
        return counter;
    }
};
