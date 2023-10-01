// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/?envType=daily-question&envId=2023-10-01

class Solution {
public:
    string reverseWords(string s) {
        int l=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                reverse(s.begin()+l,s.begin()+i);
                l=i+1;
            }
        }
        if(l!=s.size()) reverse(s.begin()+l,s.end());
        return s;
    }
};
