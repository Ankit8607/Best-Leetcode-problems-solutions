// https://leetcode.com/problems/score-of-a-string/description/?envType=daily-question&envId=2024-06-01

class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=1;i<s.size();i++) ans+=abs(s[i]-s[i-1]);
        return ans;
    }
};


// In python

// class Solution:
//     def scoreOfString(self, s: str) -> int:
//         ans=0
//         for i in range(1,len(s),1):
//             ans+=abs(ord(s[i])-ord(s[i-1]))
//         return ans


// In javascript

// /**
//  * @param {string} s
//  * @return {number}
//  */
// var scoreOfString = function(s) {
//     let ans=0;
//     for(let i=1;i<s.length;i++) ans+=Math.abs(s[i].charCodeAt(0)-s[i-1].charCodeAt(0));
//     return ans;
// };
