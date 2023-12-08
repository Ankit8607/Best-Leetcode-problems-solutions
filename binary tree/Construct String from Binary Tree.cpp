// https://leetcode.com/problems/construct-string-from-binary-tree/?envType=daily-question&envId=2023-12-08

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

    void rec(TreeNode *root,string &ans){
        if(root==NULL) return;
        ans+=to_string(root->val);
        if(root->left==NULL and root->right==NULL) return;

        ans+='(';
        rec(root->left,ans);
        ans+=')';
        if(root->right){
            ans+='(';
            rec(root->right,ans);
            ans+=')';
        }
    }

    string tree2str(TreeNode* root) {
        string ans;
        rec(root,ans);
        return ans;
    }
};
