// https://leetcode.com/problems/count-number-of-homogenous-substrings/description/?envType=daily-question&envId=2023-11-09

class Solution {
public:
    int countHomogenous(string s) {
        int ans=1,mod=1e9+7,cnt=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) cnt++;
            else cnt=1;
            ans=(ans+cnt)%mod;
        }
        return ans;
    }
};
