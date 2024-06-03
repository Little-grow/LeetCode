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
    int maxDiameterSoFar = 0;
    int height(TreeNode* root) {
        if (!root)
            return 0;

        int l = height(root->left);
        int r = height(root->right);

        maxDiameterSoFar = max(maxDiameterSoFar, l + r);
        return 1 + max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        height(root);
        return maxDiameterSoFar;
    }
};