// https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

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
    int flag=0;
    void rec(TreeNode *root, vector<TreeNode*> &v,int val){
        if(root==NULL) return;

        rec(root->left,v,val);
        if(flag==0 and val<root->val){
            TreeNode* head=new TreeNode(val);
            v.push_back(head);
            flag=1;
        }
        v.push_back(root);
        rec(root->right,v,val);
    }

    TreeNode* build(int l, int r, vector<TreeNode*> &v){
        if(l>r) return NULL;

        int mid=(l+r)/2;
        v[mid]->left=build(l,mid-1,v);
        v[mid]->right=build(mid+1,r,v);
        return v[mid];
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        vector<TreeNode*>v;
        rec(root,v,val);
        TreeNode* head=new TreeNode(val);
        if(flag==0) v.push_back(head);
        return build(0,v.size()-1,v);
    }
};
