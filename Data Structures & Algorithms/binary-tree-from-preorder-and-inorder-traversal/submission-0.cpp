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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 && inorder.size() == 0){
            return nullptr;
        }
        int root = preorder.front();
        TreeNode *rootNode = new TreeNode(root);
        auto root_ind = find(inorder.begin(), inorder.end(), root);
        size_t len = root_ind - inorder.begin();
        vector<int> left_in(inorder.begin(), root_ind);
        vector<int> left_pre(preorder.begin() + 1, preorder.begin() + 1 + len);
        rootNode->left = buildTree(left_pre, left_in);
        vector<int> right_in(root_ind + 1, inorder.end());
        vector<int> right_pre(preorder.begin() + 1 + len, preorder.end());
        rootNode->right = buildTree(right_pre, right_in);
        return rootNode;
    }
};
