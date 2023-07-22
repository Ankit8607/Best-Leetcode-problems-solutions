// https://leetcode.com/problems/knight-probability-in-chessboard/description/

class Solution {
public:

    vector<int>movex={1,2,2,1,-1,-2,-2,-1};
    vector<int>movey={2,1,-1,-2,-2,-1,1,2};

    double rec(int i, int j, int k, int n,vector<vector<vector<double>>>&dp){

        if(i<0 || i>=n || j<0 || j>=n) return 0;

        if(k==0) return 1;

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        double  ans=0;
        for(int m=0;m<8;m++){
            ans+=rec(i+movex[m],j+movey[m],k-1,n,dp);
        }

        return dp[i][j][k]=ans/8;
    }

    double knightProbability(int n, int k, int row, int column) {
        if(!k) return 1;
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        double ans=rec(row,column,k,n,dp);
        return ans;
    }
};
