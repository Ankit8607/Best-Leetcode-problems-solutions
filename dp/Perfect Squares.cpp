// https://leetcode.com/problems/perfect-squares/description/?envType=daily-question&envId=2024-02-08

class Solution {
public:

    int rec(int level,int sum,vector<vector<int>>&dp,vector<int>&arr){
        if(level==arr.size()){
            if(sum==0) return 0;
            return 1e9;
        }
        if(sum<0) return 1e9;

        if(dp[level][sum]!=-1) return dp[level][sum];

        int ans=min(rec(level+1,sum,dp,arr),1+rec(level,sum-arr[level],dp,arr));

        return dp[level][sum]=ans;
    }

    int numSquares(int n) {
        vector<int>arr;
        for(int i=1;i*i<=n;i++) arr.push_back(i*i);
        vector<vector<int>>dp(arr.size(),vector<int>(n+1,-1));
        return rec(0,n,dp,arr);
    }
};
