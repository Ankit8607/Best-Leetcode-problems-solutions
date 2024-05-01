// https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=daily-question&envId=2024-05-01

class Solution {
public:
    string reversePrefix(string word, char ch) {
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                reverse(word.begin(),word.begin()+i+1);
                return word;
            }
        }
        return word;
    }
};


// In python

// class Solution:
//     def reversePrefix(self, word: str, ch: str) -> str:
//         ans=""
//         flag=1
//         for i in word:
//             if i==ch and flag:
//                 ans+=i
//                 flag=0
//                 ans=ans[::-1]
//             else: ans+=i
//         return ans


// In javascript

// /**
//  * @param {string} word
//  * @param {character} ch
//  * @return {string}
//  */
// var reversePrefix = function(word, ch) {
//     let ans="",once=1;
//     for(let i of word){
//         ans+=i;
//         if(i==ch && once){
//             ans=ans.split('').reverse().join('');
//             once=0;
//         }
//     }
//     return ans;
// };
