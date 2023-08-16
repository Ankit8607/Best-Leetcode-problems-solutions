// https://leetcode.com/problems/coin-change/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:

    int rec(int level,int rem,vector<int>&arr,vector<vector<int>>&dp){
        if(rem<0) return -1e9;
        if(rem==0) return 0;
        if(level==arr.size()) return -1e9;

        if(dp[level][rem]!=-1) return dp[level][rem];

        int &ans=dp[level][rem];
        ans=1+rec(level,rem-arr[level],arr,dp);
        int res=rec(level+1,rem,arr,dp);
        if(ans<0 and res>=0) return ans=res;
        else if(res>=0) return ans=min(ans,res);
        else if(ans>=0) return ans;
        return ans=-1e9;
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),greater<int>());
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int t=rec(0,amount,coins,dp);
        return t>=0?t:-1;
    }
};
