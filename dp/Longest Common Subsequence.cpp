// https://leetcode.com/problems/longest-common-subsequence/description/?envType=daily-question&envId=2024-01-25

class Solution {
public:

    int rec(int i,int j,string &a,string &b,vector<vector<int>>&dp){
        if(i==a.size() || j==b.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;
        if(a[i]==b[j]) ans=1+rec(i+1,j+1,a,b,dp);
        else ans=max(rec(i+1,j,a,b,dp),rec(i,j+1,a,b,dp));

        return dp[i][j]=ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return rec(0,0,text1,text2,dp);
    }
};
