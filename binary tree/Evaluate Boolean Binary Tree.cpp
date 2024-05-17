// https://leetcode.com/problems/evaluate-boolean-binary-tree/description/?envType=daily-question&envId=2024-05-16

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
    bool evaluateTree(TreeNode* root) {
        if(root->val<2) return root->val;

        if(root->val==2) return evaluateTree(root->left) | evaluateTree(root->right);
        return evaluateTree(root->left) & evaluateTree(root->right);
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
//     def evaluateTree(self, root: Optional[TreeNode]) -> bool:
//         if root.val<2: return root.val

//         if root.val==2: return self.evaluateTree(root.left) | self.evaluateTree(root.right)
//         return self.evaluateTree(root.left) & self.evaluateTree(root.right)


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
//  * @return {boolean}
//  */
// var evaluateTree = function(root) {
//     if(root.val<2) return root.val

//     if(root.val==2) return evaluateTree(root.left) | evaluateTree(root.right);
//     return evaluateTree(root.left) & evaluateTree(root.right);
// };
