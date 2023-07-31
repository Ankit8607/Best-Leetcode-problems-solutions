// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/

class Solution {
public:

    int rec(int i,int j,int n,int m, string &a, string &b, vector<vector<int>>&dp){
        if(i>=n and j>=m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;
        if(i>=n) ans=rec(i,j+1,n,m,a,b,dp)+(int)(b[j]);
        else if(j>=m) ans=rec(i+1,j,n,m,a,b,dp)+(int)(a[i]);
        else if(a[i]==b[j]) ans=rec(i+1,j+1,n,m,a,b,dp);
        else ans=min(rec(i+1,j,n,m,a,b,dp)+(int)(a[i]),rec(i,j+1,n,m,a,b,dp)+(int)(b[j]));

        return dp[i][j]=ans;
    }

    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return rec(0,0,n,m,s1,s2,dp);
    }
};
