// https://leetcode.com/problems/number-of-islands/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:

    void dfs(int i,int j,vector<vector<char>>&g,vector<vector<int>>&vis){
        if(i>=g.size() || j>=g[0].size() || i<0 || j<0 || g[i][j]=='0' || vis[i][j]) return ;

        vis[i][j]=1;
        dfs(i+1,j,g,vis);
        dfs(i-1,j,g,vis);
        dfs(i,j+1,g,vis);
        dfs(i,j-1,g,vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ 
                if(grid[i][j]=='1' and !vis[i][j]){ 
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};
