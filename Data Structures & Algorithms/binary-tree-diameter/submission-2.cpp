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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        int diameter = left_height + right_height;
        int sub = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return max(sub , diameter);
    }

    int height(TreeNode* node){
        if (!node)
            return 0;
        return 1 + std::max(height(node->left), height(node->right));
    }
};
