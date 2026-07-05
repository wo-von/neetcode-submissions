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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        stack<pair<TreeNode*, int>> s;
        int max_depth = 0;
        s.push({root, 1});
        while (!s.empty()){
            TreeNode* tmp = s.top().first;
            int d = s.top().second;
            s.pop();
            if (tmp) {
                max_depth = std::max(max_depth, d);
                s.push({tmp->left, d + 1});
                s.push({tmp->right, d+1});
            }
        }
        return max_depth;
    }
};
