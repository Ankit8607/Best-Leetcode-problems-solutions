// https://leetcode.com/problems/out-of-boundary-paths/description/?envType=daily-question&envId=2024-01-26

class Solution {
public:
    int dp[51][51][51],mod=1e9+7;

    int rec(int i,int j,int n,int m,int mx){
        if(i<0 || i>=n || j<0 || j>=m) return 1;
        if(mx==0) return 0;

        if(dp[i][j][mx]!=-1) return dp[i][j][mx];

        int ans=(rec(i+1,j,n,m,mx-1)+rec(i,j-1,n,m,mx-1))%mod+(rec(i,j+1,n,m,mx-1)+rec(i-1,j,n,m,mx-1))%mod;

        return dp[i][j][mx]=ans%mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return rec(startRow,startColumn,m,n,maxMove);
    }
};
