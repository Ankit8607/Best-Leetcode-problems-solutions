// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24

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

    int rec(TreeNode* root, int mask){
        if(root==NULL) return 0;

        int value=root->val-1,ans;
        if(root->left==NULL and root->right==NULL) return ((((mask^(1<<value)) & ((mask^(1<<value))-1))==0)?1:0);

        return rec(root->left,(mask^(1<<value))) + rec(root->right,(mask^(1<<value)));
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        return rec(root,0);
    }
};
