// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
    vector<string>v={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void rec(int level, string &digits,vector<string>&ans, string s){
        if(level==digits.size()){
            ans.push_back(s);
            return;
        }

        for(auto i: v[digits[level]-'2']) rec(level+1,digits,ans,s+i);
    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0) return ans;
        string s;
        rec(0,digits,ans,s);
        return ans;
    }
};
