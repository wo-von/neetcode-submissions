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
    static bool left_check(int val, int limit){
        return val < limit;
    }
    static bool right_check(int val, int limit){
        return val > limit;
    }

    bool validator(TreeNode* node, int number, bool (*check)(int val, int limit)){
        if (!node)
            return true;
        if (!check(node->val, number))
            return false;
        return validator(node->left, number, check)
            && validator(node->right, number, check);
    }

    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;

        if (!validator(root->left, root->val, left_check)
            || !validator(root->right, root->val, right_check))
            return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};