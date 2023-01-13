// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    int maxAncestorDiff(TreeNode* root,int mx=-1e9,int mn=1e9) {
        if(root==NULL){
            if(mx!=-1e9 and mn!=1e9) return mx-mn;
            return 0;
        }

        return max(maxAncestorDiff(root->left,max(mx,root->val),min(mn,root->val)),maxAncestorDiff(root->right,max(mx,root->val),min(mn,root->val)));
    }
};
