/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // root null to width 0 BASE CASE
        if (root == NULL)
            return 0;
        int ans = 0;
        // queue of pair node aur uska index
        queue<pair<TreeNode*, long long>> q; 
        // 0 indexed tree
        q.push({root, 0});

        while (!q.empty()) { 
            int n = q.size();
            // finding the miin to minus from all index in that level
            long long mn = q.front().second; 
            long long first, last;           

            for (int i = 0; i < n;
                 i++) { 

                // maintaining overflow
                long long curr =  q.front().second - mn; 
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0)
                    first = curr;
                if (i == n - 1)
                    last = curr;

                if (node->left)
                    q.push({node->left, curr * 2 + 1});
                if (node->right)
                    q.push({node->right, curr * 2 + 2});
            }
            ans = max((long long)ans, last - first + 1);
        }
        return ans;
    }
};