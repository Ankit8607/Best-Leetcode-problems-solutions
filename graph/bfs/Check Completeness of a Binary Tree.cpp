// https://leetcode.com/problems/check-completeness-of-a-binary-tree/

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
    bool isCompleteTree(TreeNode* root) {
        int level=1,flag=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int tot=pow(2,level++);
            int i=0;
            while(i<tot){
                TreeNode* t=q.front().first; q.pop();
                if(t->left) q.push({t->left,i++});
                else flag=1,i++;
                if(t->right) q.push({t->right,i++});
                else flag=1,i++;
            }
            if(flag){
                // cout<<"hi";
                int dem=0;
                while(!q.empty()){
                    if(q.front().second!=dem) return 0;
                    dem++;
                    if(q.front().first->left) q.push({q.front().first->left,-1});
                    if(q.front().first->right) q.push({q.front().first->right,-1});
                    q.pop();
                }
            }
        }
        return 1;
    }
};
