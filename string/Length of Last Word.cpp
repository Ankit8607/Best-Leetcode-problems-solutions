// https://leetcode.com/problems/length-of-last-word/description/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int i=n-1;
        while(s[i]==' ') i--;
        int ans=0;
        while(i>=0 and s[i]!=' ') i--,ans++;
        return ans;
    }
};


In python 

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = s.split()
        return len(words[-1])


In javascript

/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    const words = s.trim().split(" ");
    console.log(words);
    return words[words.length - 1].length;
};
