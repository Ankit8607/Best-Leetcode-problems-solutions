// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sumNumbers(TreeNode* root,int ans=0) {
        if(root==NULL) return 0;
        if(root->left==NULL and root->right==NULL) return ans*10+root->val;

        ans=ans*10+root->val;
        return sumNumbers(root->left,ans)+sumNumbers(root->right,ans);
    }
};
