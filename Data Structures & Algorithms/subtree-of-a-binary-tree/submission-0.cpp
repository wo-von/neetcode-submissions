class Solution {
public:
    bool same(TreeNode* a, TreeNode* b) {
        if (!a || !b) return a == b;               // both null → true, one null → false
        return a->val == b->val
            && same(a->left, b->left)
            && same(a->right, b->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;                    // ran out of tree, no match here
        return same(root, subRoot)                  // match rooted at this node?
            || isSubtree(root->left, subRoot)       // or somewhere in the left subtree?
            || isSubtree(root->right, subRoot);     // or in the right?
    }
};