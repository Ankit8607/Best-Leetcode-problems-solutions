// https://leetcode.com/problems/leaf-similar-trees/description/?envType=daily-question&envId=2024-01-09

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

    void rec(TreeNode* root, vector<int>&v){
        if(root==NULL) return;

        if(root->left==NULL and root->right==NULL) v.push_back(root->val);
        else rec(root->left,v), rec(root->right,v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a,b;
        rec(root1,a);
        rec(root2,b);
        return a==b;
    }
};
