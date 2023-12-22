// https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2023-12-22

class Solution {
public:
    int maxScore(string s) {
        int sum=0,ans=0;
        for(auto i:s) sum+=(i-'0');
        for(int i=0;i<s.size()-1;i++) sum+=(s[i]=='0'?1:-1),ans=max(ans,sum);
        return ans;
    }
};
