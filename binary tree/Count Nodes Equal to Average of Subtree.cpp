// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/?envType=daily-question&envId=2023-11-02

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
    int ans=0;

    pair<int,int> rec(TreeNode *root){
        if(root==NULL) return {0,0};

        pair<int,int>left=rec(root->left);
        pair<int,int>right=rec(root->right);
        int n=1+left.second+right.second, sum=left.first+right.first+root->val;
        if(sum/n==root->val) ans++;
        return {sum,n};
    }

    int averageOfSubtree(TreeNode* root) {
        rec(root);
        return ans;
    }
};
