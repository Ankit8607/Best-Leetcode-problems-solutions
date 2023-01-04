// https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/description/

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

    int rec(TreeNode *(&root),int limit,int sum){
        if(root==NULL) return -1e9;

        int value=root->val;
        int l=rec(root->left,limit,sum+value);
        int r=rec(root->right,limit,sum+value);
        if(l==-1e9 and r==-1e9){
            if(value+sum<limit) root=NULL;
            return value;
        }
        if(l+sum+value<limit and r+sum+value<limit) root=NULL;

        return max(l,r)+value;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        rec(root, limit,0);
        return root;
    }
};
