// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int dep=0,ans=0;
        for(char &i:s){
            if(i=='(') dep++;
            else dep--;
            if(dep<0) ans++,dep=0;
        }
        ans+=dep;
        return ans;
    }
};
