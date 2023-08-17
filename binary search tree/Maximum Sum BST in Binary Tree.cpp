// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/

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

    pair<int,pair<int,int>> rec(TreeNode* root, int &ans){
        if(root==NULL) return {0,{0,0}};

        pair<int,pair<int,int>> a=rec(root->left,ans);
        pair<int,pair<int,int>> b=rec(root->right,ans);
        int v=root->val;
        if((root->left==NULL || v>a.second.second) and (root->right==NULL || v<b.second.first)){
            int t=a.first+b.first+v; ans=max(ans,t);
            return {t,{root->left==NULL?v:a.second.first,root->right==NULL ? v:b.second.second}};
        }

        return {0,{INT_MIN,INT_MAX}};
    }

    int maxSumBST(TreeNode* root) {
        int ans=0;
        rec(root,ans);
        return ans;
    }
};
