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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int leftHeight = 0;
        int rightHeight = 0;
        
        TreeNode* leftPtr = root;
        TreeNode* rightPtr = root;
        //checking max left hieght
        while (leftPtr) {
            leftHeight++;
            leftPtr = leftPtr->left;
        }
        // checking max right hieght
        while (rightPtr) {
            rightHeight++;
            rightPtr = rightPtr->right;
        }
        //if tree is perfect left ==right
        if (leftHeight == rightHeight) {
            return pow(2,leftHeight) - 1;
        }
        // nahi to basic reccursion se no of node
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};