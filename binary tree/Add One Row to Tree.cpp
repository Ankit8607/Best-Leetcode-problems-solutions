// https://leetcode.com/problems/add-one-row-to-tree/description/?envType=daily-question&envId=2024-04-16

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

    void rec(TreeNode *root,int &val, int dep){
        if(root==NULL) return;
        if(dep==1){
            TreeNode *l=new TreeNode(val,root->left,NULL);
            TreeNode *r=new TreeNode(val,NULL,root->right);
            root->left=l; root->right=r;
        }
        rec(root->left,val,dep-1);
        rec(root->right,val,dep-1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *t=new TreeNode(val);
            t->left=root;
            return t;
        }
        rec(root,val,--depth);
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
//     def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
//         def rec(root,val,dep):
//             if root==None: return
//             if dep==1:
//                 l=TreeNode(val,root.left,None)
//                 r=TreeNode(val,None,root.right)
//                 root.left=l 
//                 root.right=r
//             rec(root.left,val,dep-1)
//             rec(root.right,val,dep-1)
            
//         if depth==1:
//             return TreeNode(val,root,None)
//         rec(root,val,depth-1)
//         return root


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
//  * @param {number} val
//  * @param {number} depth
//  * @return {TreeNode}
//  */
// var addOneRow = function(root, val, depth) {
//     if(depth==1) return new TreeNode(val,root,null);
//     rec(root,val,depth-1);
//     return root;
// };

// function rec(root,val,dep){
//     if(root==null) return;
//     if(dep==1){
//         let l=new TreeNode(val,root.left,null);
//         let r=new TreeNode(val,null,root.right);
//         root.left=l; root.right=r;
//     }
//     rec(root.left,val,dep-1);
//     rec(root.right,val,dep-1);
// };
