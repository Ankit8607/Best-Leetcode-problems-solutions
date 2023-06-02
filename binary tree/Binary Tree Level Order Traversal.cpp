// https://leetcode.com/problems/binary-tree-level-order-traversal/

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

void rec(int level, TreeNode *root, vector<vector<int>>&ans){
    if(!root) return;

    if(ans.size()<=level) ans.resize(level+1);
    ans[level].push_back(root->val);
    rec(level+1, root->left, ans);
    rec(level+1, root->right, ans);

    return;
}

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        rec(0,root,ans);
        return ans;
    }
};
