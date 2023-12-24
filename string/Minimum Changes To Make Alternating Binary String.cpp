// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/?envType=daily-question&envId=2023-12-24

class Solution {
public:
    int minOperations(string s) {
        int one=0,zero=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') one++;
            else zero++;
            swap(one,zero);
        }
        return min(one,zero);
    }
};
