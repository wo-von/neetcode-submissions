class Solution {
private:
    int res = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);          // called for the side effect
        return res;
    }

    int dfs(TreeNode* node){
        if (!node) return 0;

        int left  = max(dfs(node->left),  0);   // one call each, clamped
        int right = max(dfs(node->right), 0);

        res = max(res, node->val + left + right);   // fork allowed here

        return node->val + max(left, right);        // one arm only
    }
};