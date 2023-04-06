// https://leetcode.com/problems/number-of-closed-islands/

class Solution {
public:
    int n,m;
    int dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>>& grid){
        if(i<0 || i>=n || j<0 || j>=m ) return 0;
        if(grid[i][j] || vis[i][j]==1) return 1;
        
        vis[i][j]=1;
        int ans=1;
        if(!dfs(i+1,j,vis,grid)) ans=0;
        if(!dfs(i,j+1,vis,grid)) ans=0;
        if(!dfs(i-1,j,vis,grid)) ans=0;
        if(!dfs(i,j-1,vis,grid)) ans=0;

        return ans;
    }

    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 and vis[i][j]==0)
                    ans+=dfs(i,j,vis,grid);
            }
        }
        return ans;
    }
};
