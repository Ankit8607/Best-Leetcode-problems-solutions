// https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    int n,m,cnt=0;

    int dfs(int i, int j, vector<vector<int>>&vis,vector<vector<int>>& grid){
        if(i>=n || i<0 || j<0 || j>=m) return 1;
        if(grid[i][j]==0 || vis[i][j]==1) return 0;
        vis[i][j]=1;
        cnt++;

        int ans=0;
        ans|=dfs(i+1,j,vis,grid); 
        ans|=dfs(i-1,j,vis,grid); 
        ans|=dfs(i,j+1,vis,grid); 
        ans|=dfs(i,j-1,vis,grid);

        return ans; 
    }

    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] and !vis[i][j] and !dfs(i,j,vis,grid)) ans+=cnt;
                cnt=0;
            }
        }
        return ans;
    }
};
