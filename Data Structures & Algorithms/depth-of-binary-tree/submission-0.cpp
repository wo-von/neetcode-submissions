//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(): val(0), left(nullptr), right(nullptr) {}
//    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
//    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
//};

class Solution {
public:
    int depthDFS(TreeNode* node, int d){
        int depth_left = d;
        int depth_right = d;
        if (node->left){
            depth_left = depthDFS(node->left, d + 1);
        }
        if (node->right){
            depth_right = depthDFS(node->right, d + 1);
        }
        return max(depth_right, depth_left);
    }
    
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int depth = 1;
        depth = depthDFS(root, depth);
        return depth;        
    }
};
