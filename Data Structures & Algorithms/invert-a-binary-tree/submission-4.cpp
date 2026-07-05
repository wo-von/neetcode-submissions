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
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return nullptr;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()){
            TreeNode* tmp = s.top(); s.pop();
            std::swap(tmp->left, tmp->right);
            if (tmp->left) s.push(tmp->left);
            if (tmp->right) s.push(tmp->right);
        }
        return root;
    }
};
