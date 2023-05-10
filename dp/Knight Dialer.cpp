// https://leetcode.com/problems/knight-dialer/

class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>>moves{
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {0,3,9},
        {},
        {0,1,7},
        {2,6},
        {1,3},
        {2,4}
    };

    int rec(int num,int rem, vector<vector<int>> &dp){
        if(rem==0) return 1;

        if(dp[num][rem]!=-1) return dp[num][rem];

        int ans=0;
        for(auto &i:moves[num]){
            ans+=rec(i,rem-1,dp)%mod;
            ans%=mod;
        }

        return dp[num][rem]=ans;
    }

    int knightDialer(int n) {
        vector<vector<int>>dp(10,vector<int>(n+1,-1));
        int ans=0;
        for(int i=0;i<10;i++){
            ans+=rec(i,n-1,dp)%mod;
            ans%=mod;
        }
        return ans;
    }
};
