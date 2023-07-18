// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/description/

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
    int ind=0;
    int find(int i,string s){
        int res=0;
        while(i<s.size() && s[i]<='9' && s[i]>='0'){
            res=res*10+(s[i]-'0');
            i++;
        }
        ind=i;
        return res;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        TreeNode *root=new TreeNode(find(0,traversal));
        int i=ind,n=traversal.size();
        int dep=0;
        stack<TreeNode*>st;
        TreeNode *head=root;
        st.push(head);
        while(i<n){
            int cnt=0;
            while(i<n and traversal[i]=='-') cnt++,i++;
            int val=find(i,traversal);
            i=ind;
            head=st.top();
            if(cnt>dep){
                head->left=new TreeNode(val);
                head=head->left;
                st.push(head);
                dep++;
            }
            else{
                while(dep>=cnt){
                    st.pop();
                    dep--;
                }
                st.top()->right=new TreeNode(val);
                st.push(st.top()->right);
                dep++;
            }
        }
        return root;
    }
};
