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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;

        deque <TreeNode*> q;
        q.push_back(root);
        bool forward = true;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;
            while (sz--) {
                TreeNode* cur;
                if (forward) {
                    cur = q.front();
                    q.pop_front();
                  
                   if (cur->left)
                        q.push_back(cur->left);

                    if (cur->right)
                        q.push_back(cur->right);

                } else {
                    cur = q.back();
                    q.pop_back();

                    if (cur->right)
                        q.push_front(cur->right);
                   
                    if (cur->left)
                        q.push_front(cur->left);
                   
                }
                level.push_back(cur->val);
            }
            forward = !forward;
            res.push_back(level);
        }
        return res;
    }
};
