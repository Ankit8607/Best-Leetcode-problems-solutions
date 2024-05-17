// https://leetcode.com/problems/delete-leaves-with-a-given-value/description/?envType=daily-question&envId=2024-05-17

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL) return root;

        root->left=removeLeafNodes(root->left,target);
        root->right=removeLeafNodes(root->right,target);
        if(root->left==NULL and root->right==NULL and root->val==target)  return NULL;
        return root;
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
//     def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
//         if root==None: return root

//         root.left=self.removeLeafNodes(root.left,target)
//         root.right=self.removeLeafNodes(root.right,target)
//         if root.left==None and root.right==None and root.val==target:  return None
//         return root


//   In javascript

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
//  * @param {number} target
//  * @return {TreeNode}
//  */
// var removeLeafNodes = function(root, target) {
//     if(root==null) return root;

//     root.left=removeLeafNodes(root.left,target);
//     root.right=removeLeafNodes(root.right,target);
//     if(root.left==null && root.right==null && root.val==target)  return null;
//     return root;
// };
