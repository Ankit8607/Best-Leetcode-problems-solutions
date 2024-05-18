// https://leetcode.com/problems/distribute-coins-in-binary-tree/description/?envType=daily-question&envId=2024-05-18


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
    int rec(TreeNode* root,int &res){
        if(root==NULL) return 0;

        int ans=root->val+rec(root->left,res)+rec(root->right,res);
        ans--;
        res+=abs(ans);
        return ans;
    }

    int distributeCoins(TreeNode* root) {
        int res=0;
        rec(root,res);
        return res;
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
//     def distributeCoins(self, root: Optional[TreeNode]) -> int:
//         def rec(root,res):
//             if root==None: return 0

//             ans=root.val+rec(root.left,res)+rec(root.right,res)
//             ans-=1
//             res[0]+=abs(ans)
//             return ans
//         res=[0]
//         rec(root,res)
//         return res[0]


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
// var distributeCoins = function(root) {
//     let res={count:0};
//     rec(root,res);
//     return res.count;
// };
// var rec=(root,res)=>{
//     if(root==null) return 0;

//     let ans=root.val+rec(root.left,res)+rec(root.right,res);
//     ans--;
//     res.count+=Math.abs(ans);
//     return ans;
// }
