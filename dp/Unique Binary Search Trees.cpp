// https://leetcode.com/problems/unique-binary-search-trees/description/

class Solution {
public:

    int rec(int l,int r, vector<vector<int>>&dp){
        if(l>=r) return 1;

        if(dp[l][r]!=-1) return dp[l][r];

        int ans=0;
        for(int i=l;i<=r;i++) ans+=rec(l,i-1,dp)*rec(i+1,r,dp);

        return dp[l][r]=ans;
    }

    int numTrees(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return rec(0,n-1,dp);
    }
};
