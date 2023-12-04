// https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/?envType=daily-question&envId=2023-12-04

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        for(int i=2;i<num.size();i++){
            if(num[i]==num[i-1] and num[i]==num[i-2] and (ans.size()>0?(num[i]>ans[0]):1)) ans = num.substr(i-2,3);
        }
        return ans;
    }
};
