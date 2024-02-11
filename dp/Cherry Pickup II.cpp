// https://leetcode.com/problems/cherry-pickup-ii/?envType=daily-question&envId=2024-02-11

class Solution {
public:
    int dp[70][70][70];

    int rec(int a,int b,int d,vector<vector<int>>&grid){
        if(b>d || b<0 || d>=grid[0].size()) return 0;
        if(a==grid.size()) return 0;

        if(dp[a][b][d]!=-1) return dp[a][b][d];

        int ans=max({rec(a+1,b-1,d-1,grid),rec(a+1,b-1,d,grid),rec(a+1,b-1,d+1,grid)});
        ans=max(ans,max({rec(a+1,b,d-1,grid),rec(a+1,b,d,grid),rec(a+1,b,d+1,grid)}));
        ans=max(ans,max({rec(a+1,b+1,d-1,grid),rec(a+1,b+1,d,grid),rec(a+1,b+1,d+1,grid)}));

        if(b==d) ans+=grid[a][b];
        else ans+=grid[a][b]+grid[a][d];
        return dp[a][b][d]=ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,grid[0].size()-1,grid);
    }
};
