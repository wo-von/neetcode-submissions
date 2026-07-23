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
    vector<bool> balanced;
    int height(TreeNode* node) {
        if (!node)
            return 0;
        else {
            int height_left = height(node->left);
            int height_right = height(node->right);
            if (abs(height_left - height_right) > 1)
                balanced.push_back(false);
            else
                balanced.push_back(true);
            return max(height_left, height_right) + 1;
        }
    }
    
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        height(root);
        for (auto b: balanced){
            if (b == false)
                return false;
        }
        return true;
    }
};
