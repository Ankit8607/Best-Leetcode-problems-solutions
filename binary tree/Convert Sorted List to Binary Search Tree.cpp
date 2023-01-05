// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    void rec(TreeNode* (&root),int l,int r,vector<int>&ans) {
        if(l>r) return;

        int mid=(l+r)/2;
        root=new TreeNode(ans[mid]);
        rec(root->left,l,mid-1,ans);
        rec(root->right,mid+1,r,ans);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        vector<int>ans;
        while(head){
            ans.push_back(head->val);
            head=head->next;
        }
        int n=ans.size();
        TreeNode *root;
        rec(root,0,n-1,ans);
        return root;
    }
};
