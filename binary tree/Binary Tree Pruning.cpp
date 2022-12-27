// https://leetcode.com/problems/binary-tree-pruning/description/

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
    int rec(TreeNode *root){
        if(root==NULL) return 0;

        int l=rec(root->left);
        if(l==0) root->left=NULL;
        int r=rec(root->right);
        if(r==0) root->right=NULL;
        return root->val+l+r;
    }
    TreeNode* pruneTree(TreeNode* root) {
        int t=rec(root);
        return t?root:NULL;
    }
};
