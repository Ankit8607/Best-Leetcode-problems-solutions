// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=daily-question&envId=2024-02-13

class Solution {
public:

    bool is_palin(string &s){
        int n=s.size();
        for(int i=0;i<n/2;i++)
            if(s[i]!=s[n-i-1]) return 0;
        return 1;
    }

    string firstPalindrome(vector<string>& words) {
        for(auto &i:words)
            if(is_palin(i)) return i;
        return "";
    }
};
