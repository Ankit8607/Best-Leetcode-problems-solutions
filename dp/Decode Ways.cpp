// https://leetcode.com/problems/decode-ways/description/?envType=daily-question&envId=2023-12-25

class Solution {
public:

    int rec(int level, int last, string &s,vector<vector<int>>&dp){
        if(level==s.size()) return last==0;

        if(dp[level][last]!=-1) return dp[level][last];

        int ans=0;
        if(last==0 and s[level]!='0')ans=rec(level+1,0,s,dp)+rec(level+1,s[level]-'0',s,dp);
        else if(last!=0 and (last*10+(s[level]-'0'))<27) ans=rec(level+1,0,s,dp);

        return dp[level][last]=ans;
    }

    int numDecodings(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(27,-1));
        return rec(0,0,s,dp);
    }
};
