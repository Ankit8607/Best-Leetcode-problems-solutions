// https://leetcode.com/problems/range-sum-of-bst/description/?envType=daily-question&envId=2024-01-08

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        return rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high)+((root->val<=high and root->val>=low)?root->val:0);
    }
};
