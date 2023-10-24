// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/?envType=daily-question&envId=2023-10-24

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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int>ans;
        if(root) q.push(root);
        while(!q.empty()){
            int res=1<<31;
            int t=q.size();
            while(t--){
                res=max(res,q.front()->val);
                if(q.front()->left)q.push(q.front()->left);
                if(q.front()->right)q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(res);
        }
        return ans;
    }
};
