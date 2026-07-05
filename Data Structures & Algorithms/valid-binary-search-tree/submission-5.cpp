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
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        queue<tuple<TreeNode*, long, long>> q;
        q.push(make_tuple(root, LONG_MIN, LONG_MAX));
        while (!q.empty()){
            auto [node, min, max] = q.front();
            q.pop();
            if (node->val<=min || node->val>=max)
                return false;
            if (node->left)
                q.push(make_tuple(node->left, min, node->val));
            if (node->right)
                q.push(make_tuple(node->right, node->val, max));
        }
        return true;
    }
};
