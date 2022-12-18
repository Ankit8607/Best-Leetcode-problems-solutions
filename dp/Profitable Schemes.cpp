// https://leetcode.com/problems/profitable-schemes/

class Solution {
public:
    int mod=1e9+7;
    int dp[101][101][101];
    int rec(int level,int n, int minProfit, vector<int>& group, vector<int>& profit){
        if(n<0) return 0;
        if(level==group.size()){ 
            if(minProfit==0) return 1;
            return 0;
        }

        if(dp[level][n][minProfit]!=-1) return dp[level][n][minProfit];

        int ans=rec(level+1,n,minProfit,group,profit)%mod;
        ans+=rec(level+1,n-group[level],max(0,minProfit-profit[level]),group,profit)%mod;
        return dp[level][n][minProfit]=ans%mod;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return rec(0,n,minProfit,group,profit);
    }
};
