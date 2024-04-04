// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/?envType=daily-question&envId=2024-04-04

class Solution {
public:
    int maxDepth(string s) {
        int ans=0,cnt=0;
        for(auto i:s){
            if(i=='(') cnt++;
            else if(i==')') cnt--;
            ans=max(ans,cnt);
        }
        return ans;
    }
};


// In python 

// class Solution:
//     def maxDepth(self, s: str) -> int:
//         ans,cnt=0,0
//         for i in s:
//             if i=='(':
//                 cnt+=1
//             elif i==')':
//                 cnt-=1
//             ans=max(ans,cnt)
//         return ans


// In javscript

// /**
//  * @param {string} s
//  * @return {number}
//  */
// var maxDepth = function(s) {
//     let ans=0,cnt=0;
//         for(let i of s){
//             if(i=='(') cnt++;
//             else if(i==')') cnt--;
//             ans=Math.max(ans,cnt);
//         }
//         return ans;
// };
