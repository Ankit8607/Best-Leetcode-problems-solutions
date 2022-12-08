// https://leetcode.com/problems/coin-change-ii/description/

class Solution {
public:
    int dp[310][5100];
    int rec(int level,int amount,vector<int>&coins){
        if(amount==0) return 1;
        if(level==coins.size()) return 0;

        if(dp[level][amount]!=-1) return dp[level][amount];

        int ans=rec(level+1,amount,coins);
        if(coins[level]<=amount){
            ans+=rec(level,amount-coins[level],coins);
        }

        return dp[level][amount]=ans;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return rec(0,amount,coins);
    }
};
