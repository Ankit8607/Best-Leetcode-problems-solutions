// https://leetcode.com/problems/find-mode-in-binary-search-tree/?envType=daily-question&envId=2023-11-01

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

    void rec(TreeNode* root, unordered_map<int,int>&mp){
        if(root==NULL) return;

        mp[root->val]++;
        rec(root->left,mp);
        rec(root->right,mp);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        rec(root,mp);
        map<int,vector<int>>fre;
        for(auto i:mp) fre[i.second].push_back(i.first);
        return fre.rbegin()->second;
    }
};
