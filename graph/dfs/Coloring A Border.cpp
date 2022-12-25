// https://leetcode.com/problems/coloring-a-border/

class Solution {
public:
    #define print(a) cout<<#a<<" = "<<a<<endl
    int n,m;
    void dfs(vector<vector<int>>& grid, int i, int j, int color,vector<vector<int>>&vis,int tar){
        vis[i][j] = 1;
        if((i==0 || j==0 || i==n-1 || j==m-1) || !((grid[i+1][j]==tar || vis[i+1][j]) and (grid[i-1][j]==tar || vis[i-1][j]) and (grid[i][j+1]==tar || vis[i][j+1]) and (grid[i][j-1]==tar || vis[i][j-1])) )
            grid[i][j]=color;

        if(i+1<n and grid[i+1][j]==tar and !vis[i+1][j]) dfs(grid,i+1,j,color,vis,tar);
        if(i-1>=0 and grid[i-1][j]==tar and !vis[i-1][j]) dfs(grid,i-1,j,color,vis,tar);
        if(j-1>=0 and grid[i][j-1]==tar and !vis[i][j-1]) dfs(grid,i,j-1,color,vis,tar);
        if(j+1<m and grid[i][j+1]==tar and !vis[i][j+1]) dfs(grid,i,j+1,color,vis,tar);
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        if(grid[row][col]==color) return grid;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));    
        n=grid.size();m=grid[0].size();
        dfs(grid,row,col,color,vis,grid[row][col]);
        return grid;
    }
};
