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
