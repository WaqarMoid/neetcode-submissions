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
       if (root == nullptr) return 0;
        
        // 1. Delegate to the left subtree
        int leftHeight = maxDepth(root->left);
        
        // 2. Delegate to the right subtree
        int rightHeight = maxDepth(root->right);
        
        // 3. Take the maximum of both sides and add 1 for the current node
        return max(leftHeight, rightHeight) + 1;
    }
};
