// https://leetcode.com/problems/k-inverse-pairs-array/?envType=daily-question&envId=2024-01-27

class Solution {
public:
    int mod=1e9+7;
    int rec(int level,int n,int k,vector<vector<int>>&dp){
        if(level==n) return k==0;
        
        if(dp[level][k]!=-1) return dp[level][k];

        int ans=0;
        for(int i=0;i<(n-level) && k>=i;i++){
            ans+=rec(level+1,n,k-i,dp);
            ans%=mod;
        }

        return dp[level][k]=ans;
    }

    int kInversePairs(int n, int k) {
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return rec(0,n,k,dp);
    }
};
