// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/?envType=daily-question&envId=2024-06-03


class Solution {
public:
    int appendCharacters(string s, string t) {
        int it=0,m=t.size();
        for(auto i:s){
            if(it==m) break;
            if(i==t[it]) it++;
        }
        return m-it;
    }
};


// In python

// class Solution:
//     def appendCharacters(self, s: str, t: str) -> int:
//         it,m=0,len(t)
//         for i in s:
//             if it==m: break
//             if i==t[it]: it+=1
//         return m-it


// In javascript

// /**
//  * @param {string} s
//  * @param {string} t
//  * @return {number}
//  */
// var appendCharacters = function(s, t) {
//     let it=0,m=t.length;
//     for(let i of s){
//         if(it==m) break;
//         if(i==t[it]) it++;
//     }
//     return m-it;
// };
