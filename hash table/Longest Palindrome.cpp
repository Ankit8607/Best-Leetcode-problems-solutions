// https://leetcode.com/problems/longest-palindrome/description/?envType=daily-question&envId=2024-06-04

class Solution {
public:
    int longestPalindrome(string s) {
        map<int,int>mp;
        for(auto i:s) mp[i]++;
        int ans=0,odd=0;
        for(auto i:mp){
            ans+=i.second-i.second%2;
            odd=max(odd,i.second%2);
        }
        return ans+odd;
    }
};


// In python

// class Solution:
//     def longestPalindrome(self, s: str) -> int:
//         # map<int,int>mp
//         mp={}
//         for i in s:
//             if i in mp:
//                 mp[i]+=1
//             else: mp[i]=1
//         ans,odd=0,0
//         for i in mp.values():
//             ans+=i-i%2
//             odd=max(odd,i%2)
//         return ans+odd

// In javascript

// /**
//  * @param {string} s
//  * @return {number}
//  */
// var longestPalindrome = function(s) {
//     const mp = new Map();
//     for (const i of s) {
//         mp.set(i, (mp.get(i) || 0) + 1);
//     }
//     let ans = 0;
//     let odd = 0;
//     for (const [key, value] of mp) {
//         ans += value - (value % 2);
//         odd = Math.max(odd, value % 2);
//     }
//     return ans + odd;
// };
