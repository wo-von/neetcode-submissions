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
        unordered_map<int, int> in_index;               // replaces find()
        for (int i = 0; i < static_cast<int>(inorder.size()); ++i)
            in_index[inorder[i]] = i;

        return build(preorder, 0, static_cast<int>(preorder.size()) - 1,
                     0, static_cast<int>(inorder.size()) - 1, in_index);
    }

private:
    // Builds the subtree from preorder[pre_lo..pre_hi] and inorder[in_lo..in_hi]
    TreeNode* build(const vector<int>& preorder, int pre_lo, int pre_hi,
                    int in_lo, int in_hi,
                    const unordered_map<int, int>& in_index) {
        if (pre_lo > pre_hi) return nullptr;            // was: size() == 0

        int root = preorder[pre_lo];                    // was: preorder.front()
        TreeNode* rootNode = new TreeNode(root);
        int root_ind = in_index.at(root);               // was: find(...)
        int len = root_ind - in_lo;                     // was: root_ind - inorder.begin()

        rootNode->left  = build(preorder, pre_lo + 1, pre_lo + len,      // was: left_pre
                                in_lo, root_ind - 1, in_index);          // was: left_in
        rootNode->right = build(preorder, pre_lo + 1 + len, pre_hi,      // was: right_pre
                                root_ind + 1, in_hi, in_index);          // was: right_in
        return rootNode;
    }
};