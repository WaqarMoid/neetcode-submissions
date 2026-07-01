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
    int diameterOfBinaryTree(TreeNode* root) {
    int maxdiameter=0;
    maxDepthanddiameter(root,maxdiameter);
    return maxdiameter;
    }
private:
     int maxDepthanddiameter(TreeNode* root,int &maxdiameter) {
       if (root == nullptr) return 0;
        
        
        int leftHeight= maxDepthanddiameter(root->left,maxdiameter);
        int rightHeight = maxDepthanddiameter(root->right,maxdiameter);
        
        int diameter=rightHeight+leftHeight;
        maxdiameter=max(diameter,maxdiameter);
        
        // 3. Take the maximum of both sides and add 1 for the current node
        return max(leftHeight, rightHeight) + 1;
    }
};
