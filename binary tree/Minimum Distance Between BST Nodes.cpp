// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
    void rec(TreeNode *root,vector<int>&ans){
        if(root==NULL) return;

        rec(root->left,ans);
        ans.push_back(root->val);
        rec(root->right,ans);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>ans;
        rec(root,ans);
        int res=1e9;
        for(int i=1;i<ans.size();i++) res=min(res,ans[i]-ans[i-1]);
        return res;
    }
};
