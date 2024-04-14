// https://leetcode.com/problems/sum-of-left-leaves/description/?envType=daily-question&envId=2024-04-14

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
    int sumOfLeftLeaves(TreeNode* root,int t=0) {
        if(!root) return 0;
        if(root->left==NULL and root->right==NULL and t) return root->val;
        return sumOfLeftLeaves(root->left,1)+sumOfLeftLeaves(root->right,0);
    }
};


In python

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode],t=0) -> int:
        def f(root,t):
            if not root: return 0
            if not root.left and not root.right and t: return root.val
            return f(root.left,1)+f(root.right,0) 
        return f(root,0)


In javascript

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumOfLeftLeaves = function(root) {
    return f(root,0);
};

var f=(root,t)=>{
    if(!root) return 0;
    if(root.left==null && root.right==null && t) return root.val;
    return f(root.left,1)+f(root.right,0);
};
