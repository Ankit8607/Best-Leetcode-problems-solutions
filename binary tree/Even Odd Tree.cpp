// https://leetcode.com/problems/even-odd-tree/description/?envType=daily-question&envId=2024-02-29

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
    bool isEvenOddTree(TreeNode* root) {
        int level=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            if(level%2){
                int last=1e9,t=q.size();
                while(t--){
                    int num=q.front()->val;
                    if(num>=last || num%2) return 0;
                    last=num;
                    if(q.front()->left) q.push(q.front()->left);
                    if(q.front()->right) q.push(q.front()->right);
                    q.pop();
                }
            }
            else{
                int last=-1e9,t=q.size();
                while(t--){
                    int num=q.front()->val;
                    if(num<=last || num%2==0) return 0;
                    last=num;
                    if(q.front()->left) q.push(q.front()->left);
                    if(q.front()->right) q.push(q.front()->right);
                    q.pop();
                }
            }
            level++;
        }
        return 1;
    }
};
