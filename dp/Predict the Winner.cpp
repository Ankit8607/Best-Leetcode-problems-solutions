// https://leetcode.com/problems/predict-the-winner/description/

class Solution {
public:

    int rec(int l,int r,vector<int>&nums,vector<vector<long long>>&dp){
        if(l>r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        return dp[l][r] = max(nums[l]-rec(l+1,r,nums,dp), nums[r]-rec(l,r-1,nums,dp));
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n,vector<long long>(n,-1));
        return rec(0,n-1,nums,dp)>=0;
    }
};
