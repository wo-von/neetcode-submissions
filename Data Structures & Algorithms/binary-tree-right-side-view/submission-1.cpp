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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> level;
        vector<int> res;
        level.push(root);
        while(!level.empty()){
            int level_size = level.size();
            vector<TreeNode*>level_vec;
            while(level_size > 0){
                level_vec.push_back(level.front());
                level.pop();
                level_size--;
            }
            res.push_back(level_vec.back()->val);
            for (auto& node: level_vec){
                if (node->left)
                    level.push(node->left);
                if (node->right)
                    level.push(node->right);
            }
        }
        return res;
    }
};