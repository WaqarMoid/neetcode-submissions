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
    TreeNode* invertTree(TreeNode* root) {
    if(root==nullptr) return nullptr;
    TreeNode* invertleft=invertTree(root->left);
    TreeNode* invertright=invertTree(root->right);

    root->left= invertright;
    root->right=invertleft;
    return root;
    }
};
