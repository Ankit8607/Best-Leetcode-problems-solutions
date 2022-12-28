// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
    int dp[5001][1001][3];

    int rec(int level,int last,int status,vector<int>& prices) {
        if(level==prices.size()) return 0;

        if(dp[level][last][status]!=-1) return dp[level][last][status];

        int ans=0;
        if(status==0) ans=max(rec(level+1,prices[level],1,prices),rec(level+1,last,0,prices));
        else if(status==1) ans=max(prices[level]-last+rec(level+1,0,2,prices),rec(level+1,last,1,prices));
        else ans=rec(level+1,last,0,prices);

        return dp[level][last][status]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0,prices);
    }
};
