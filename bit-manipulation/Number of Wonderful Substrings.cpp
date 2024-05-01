// https://leetcode.com/problems/number-of-wonderful-substrings/description/?envType=daily-question&envId=2024-04-30

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int>v(1025,0);
        v[0]=1;
        long long mask=0,ans=0;
        for(auto i: word){
            mask^=(1<<(i-'a'));
            ans+=v[mask];
            for(long long j=0;j<10;j++) ans+=v[((1LL<<j)^mask)];
            v[mask]++;
        }
        return ans;
    }
};


// In python

// class Solution:
//     def wonderfulSubstrings(self, word: str) -> int:
//         v=[0 for i in range(1025)]
//         v[0]=1
//         mask,ans=0,0
//         for i in word:
//             mask^=(1<<(ord(i)-ord('a')))
//             ans+=v[mask]
//             for j in range(10): ans+=v[((1<<j)^mask)]
//             v[mask]+=1
//         return ans

// In javascript

// /**
//  * @param {string} word
//  * @return {number}
//  */
// var wonderfulSubstrings = function(word) {
//     // let v=[1025,0];
//     let v=new Array(1025).fill(0);
//     v[0]=1;
//     let mask=0,ans=0;
//     for(let i of word){
//         mask^=(1<<(i.charCodeAt(0)-'a'.charCodeAt(0)));
//         ans+=v[mask];
//         for(let j=0;j<10;j++) ans+=v[((1<<j)^mask)];
//         v[mask]++;
//     }
//     return ans;
// };
