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
    int height(TreeNode *node){
        if (!node)
            return 0;
        return max(height(node->right), height(node->left)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        int height_left = height(root->left);
        int height_right = height(root->right);
        if (abs(height_left - height_right) > 1)
            return false;
        return isBalanced(root->right) && isBalanced(root->left);
    }
};
