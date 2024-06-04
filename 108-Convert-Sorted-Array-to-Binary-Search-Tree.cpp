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
    TreeNode* sortedArrayToBST(vector<int>& nums) {   
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }

    TreeNode* sortedArrayToBST(vector<int>& vals, int st, int end){
        if(st > end)
            return nullptr;
        
        int mid = (st + end) /2;
        TreeNode *root = new TreeNode(vals[mid]);
        root->left = sortedArrayToBST(vals, st, mid-1);
        root->right = sortedArrayToBST(vals, mid+1, end);

        return root;
    }
};