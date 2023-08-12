// https://leetcode.com/problems/unique-paths-ii/submissions/

class Solution {
public:

    int rec(int i,int j,int n,int m,vector<vector<int>>&arr,vector<vector<int>>&dp){
        if(i>=n || j>=m || i<0 || j<0 || arr[i][j]==1) return 0;
        if(i==n-1 and j==m-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int ans=rec(i+1,j,n,m,arr,dp)+rec(i,j+1,n,m,arr,dp);

        return dp[i][j]=ans;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return rec(0,0,n,m,obstacleGrid,dp);
    }
};
