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
    bool isBalanced(TreeNode* root) {
        return helper(root) == -1 ? false : true;  
    }

    int helper(TreeNode* root) {   
        if (root == nullptr) return 0;
        
        int left = helper(root->left);
        // CRITICAL FIX 1: If left subtree is already broken, pass -1 up immediately
        if (left == -1) return -1; 
        
        int right = helper(root->right);
        // CRITICAL FIX 2: If right subtree is already broken, pass -1 up immediately
        if (right == -1) return -1; 
        
        if (abs(left - right) <= 1) {
            return max(left, right) + 1;
        }
        else {
            return -1;
        }
    }
};
