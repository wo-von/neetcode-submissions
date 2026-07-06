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

    int height(TreeNode* node, int& diameter) {
        if (!node)
            return 0;                          // empty subtree is 0 nodes tall
        int left_height = height(node->left, diameter);
        int right_height = height(node->right, diameter);
        int path_through_node = left_height + right_height;   // edges through node
        diameter = max(diameter, path_through_node);
        return 1 + max(left_height, right_height);            // report height upward
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};