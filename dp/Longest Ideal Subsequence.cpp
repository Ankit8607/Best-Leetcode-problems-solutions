// https://leetcode.com/problems/longest-ideal-subsequence/description/?envType=daily-question&envId=2024-04-25

class Solution {
public:

    int rec(int level,int last,int k,string &s, vector<vector<int>>&dp){
        if(level==s.size()) return 0;

        if(dp[level][last]!=-1) return dp[level][last];

        int ans=rec(level+1,last,k,s,dp);
        if(last==26 || abs((s[level]-'a')-last)<=k) ans=max(ans,1+rec(level+1,s[level]-'a',k,s,dp));

        return dp[level][last]=ans;
    }

    int longestIdealString(string s, int k) {
        vector<vector<int>>dp(s.size(),vector<int>(27,-1));
        return rec(0,26,k,s,dp);
    }
};


// In python

// class Solution:
//     def longestIdealString(self, s: str, k: int) -> int:
//         dp = [[-1 for _ in range(27)] for _ in range(len(s))]

//         def rec(level, last):
//             if level == len(s):
//                 return 0

//             if dp[level][last] != -1:
//                 return dp[level][last]

//             ans = rec(level + 1, last)
//             if last == 26 or abs(ord(s[level]) - ord('a') - last) <= k:
//                 ans = max(ans, 1 + rec(level + 1, ord(s[level]) - ord('a')))
//             dp[level][last] = ans
//             return ans

//         return rec(0, 26)


// In javascript

// /**
//  * @param {string} s
//  * @param {number} k
//  * @return {number}
//  */
// var longestIdealString = function(s, k) {
//     let dp = Array.from(Array(s.length), () => Array(27).fill(-1));
//     return rec(0, 26, k, s, dp);
// };

// let rec = function(level, last, k, s, dp) {
//     if (level == s.length) return 0;
//     if (dp[level][last] != -1) return dp[level][last];
//     let ans = rec(level + 1, last, k, s, dp);
//     if (last == 26 || Math.abs((s.charCodeAt(level) - 'a'.charCodeAt(0)) - last) <= k) {
//         ans = Math.max(ans, 1 + rec(level + 1, s.charCodeAt(level) - 'a'.charCodeAt(0), k, s, dp));
//     }
//     return dp[level][last] = ans;
// }
