// https://leetcode.com/problems/max-dot-product-of-two-subsequences/

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
            
        int dp[n1+1][n2+1];
        for(int i = 0;i<=n1;i++)
        {
            for(int j = 0;j <= n2 ; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = INT_MIN;
                }
            }
        }
        
        dp[0][0] = 0;
        
        for(int i = 1;i <= n1;i++)
        {
            for(int j = 1;j <= n2;j++)
            {
                int prod  = nums1[i-1] * nums2[j-1];
                {
                    dp[i][j] = prod + max(0,dp[i-1][j-1]);
                    dp[i][j] = max(dp[i][j] ,dp[i-1][j]);
                    dp[i][j] = max(dp[i][j] ,dp[i][j-1]);
                }
            }
        }
     
        return dp[n1][n2];
    }
};


// Recursive code

class Solution {
public:

    int rec(int i,int j,int state,vector<int>&a,vector<int>&b,vector<vector<vector<int>>>&dp){
        if(i>=a.size() || j>=b.size()){
            if(state==0) return -1e9;
            return 0;
        }

        if(dp[i][j][state]!=-1) return dp[i][j][state];

        int ans=max(rec(i+1,j,state,a,b,dp),rec(i,j+1,state,a,b,dp));
        ans=max(ans,a[i]*b[j]+rec(i+1,j+1,1,a,b,dp));

        return dp[i][j][state]=ans;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,-1)));
        return rec(0,0,0,nums1,nums2,dp);
    }
};
