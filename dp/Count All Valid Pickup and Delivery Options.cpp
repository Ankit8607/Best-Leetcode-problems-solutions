// https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/

class Solution {
public:
    int countOrders(int n) {
        int mod=1e9+7;
        vector<int>dp(n+1,0);
        dp[1]=1;
        for(int i=1;i<n;i++){
            dp[i+1]=(2*i+1)*(i+1)%mod;
            dp[i+1]=1LL*dp[i]*dp[i+1]%mod;
        }
        return dp[n];
    }
};
