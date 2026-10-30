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
        index_of_.clear();
        for (int i = 0; i < static_cast<int>(inorder.size()); ++i)
            index_of_[inorder[i]] = i;           // value -> position in inorder, built once

        preorder_  = &preorder;
        next_root_ = 0;                          // walks preorder left to right
        return build(0, static_cast<int>(inorder.size()) - 1);
    }

private:
    std::unordered_map<int, int> index_of_;
    const vector<int>* preorder_ = nullptr;
    int next_root_ = 0;

    // Builds the subtree whose nodes are inorder[lo..hi]
    TreeNode* build(int lo, int hi) {
        if (lo > hi) return nullptr;             // empty range = empty subtree

        int root_val = (*preorder_)[next_root_++];
        TreeNode* node = new TreeNode(root_val);
        int mid = index_of_.at(root_val);

        node->left  = build(lo, mid - 1);        // left must come first
        node->right = build(mid + 1, hi);
        return node;
    }
};
