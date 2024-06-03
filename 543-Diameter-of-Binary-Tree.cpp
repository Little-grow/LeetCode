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
    bool isLeaf(TreeNode* root) {
        if(!root->left && !root->right)
            return true;
        return false;
    }
    pair<int, int> _diameter(TreeNode* root) {
        pair<int, int> res;

        if (isLeaf(root))
            return res;

        pair<int, int> left = make_pair(0, 0);
        pair<int, int> right = make_pair(0, 0);

        if (root->left)
            left = _diameter(root->left), res.first += 1 + left.second;

        if(root->right)
            right = _diameter(root->right), res.first += 1 + right.second;

        //diameter if in one of my children sub tree
        res.first = max(res.first, max(left.first, right.first)); 

        // normal height 
        res.second = 1 + max(left.second, right.second);
        return res;
    }
    int diameterOfBinaryTree(TreeNode* root) {
     auto res = _diameter(root);
     return res.first;
    }
};