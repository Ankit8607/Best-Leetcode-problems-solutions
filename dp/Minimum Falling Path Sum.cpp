// https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19

class Solution {
public:

    int rec(int row,int col,vector<vector<int>>&mat,vector<vector<int>>&dp){
        if(row>=mat.size()) return 0;

        if(dp[row][col]!=-1e5) return dp[row][col];

        int ans=rec(row+1,col,mat,dp);
        if(col>0) ans=min(ans,rec(row+1,col-1,mat,dp));
        if(col+1<mat[0].size()) ans=min(ans,rec(row+1,col+1,mat,dp));
        
        return dp[row][col]=ans+mat[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1e5));
        int ans=1e9;
        for(int i=0;i<matrix[0].size();i++) ans=min(ans,rec(0,i,matrix,dp));
        return ans;
    }
};
