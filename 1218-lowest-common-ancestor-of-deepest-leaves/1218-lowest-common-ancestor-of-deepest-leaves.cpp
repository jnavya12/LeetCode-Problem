class Solution {
public:
    struct Result {
        TreeNode* node;
        int depth;
    };
    
    Result dfs(TreeNode* root) {
        if (!root) return {nullptr, 0};
        
        Result left = dfs(root->left);
        Result right = dfs(root->right);
        
        if (left.depth == right.depth) {
            return {root, left.depth + 1};  
        } else if (left.depth > right.depth) {
            return {left.node, left.depth + 1};  
        } else {
            return {right.node, right.depth + 1};  
        }
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).node;
    }
};
