// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/?envType=daily-question&envId=2024-04-15

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
    int sumNumbers(TreeNode* root,int ans=0) {
        if(root==NULL) return 0;
        if(root->left==NULL and root->right==NULL) return ans*10+root->val;

        ans=ans*10+root->val;
        return sumNumbers(root->left,ans)+sumNumbers(root->right,ans);
    }
};



// In python

// # Definition for a binary tree node.
// # class TreeNode:
// #     def __init__(self, val=0, left=None, right=None):
// #         self.val = val
// #         self.left = left
// #         self.right = right
// class Solution:
//     def sumNumbers(self, root: Optional[TreeNode]) -> int:
//         def f(root,ans):
//             if root==None: return 0
//             if root.left==None and root.right==None: return ans*10+root.val

//             ans=ans*10+root.val
//             return f(root.left,ans)+f(root.right,ans)
//         return f(root,0)


// In javascript

// /**
//  * Definition for a binary tree node.
//  * function TreeNode(val, left, right) {
//  *     this.val = (val===undefined ? 0 : val)
//  *     this.left = (left===undefined ? null : left)
//  *     this.right = (right===undefined ? null : right)
//  * }
//  */
// /**
//  * @param {TreeNode} root
//  * @return {number}
//  */
// var sumNumbers = function(root) {
//     return f(root,0);
// };
// var f=(root,ans)=>{
//     if(root==null) return 0;
//     if(root.left==null && root.right==null) return ans*10+root.val;
//     ans=ans*10+root.val;
//     return f(root.left,ans)+f(root.right,ans);
// }
