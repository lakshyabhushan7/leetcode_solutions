class Solution {
public:
    bool helper(TreeNode *root, long long mn, long long mx) {
        if (root == NULL) return true;
        if (root->val >= mx || root->val <= mn) return false;
        return helper(root->left, mn, root->val) && helper(root->right, root->val, mx);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};