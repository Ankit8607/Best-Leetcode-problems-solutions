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



// In python

// class Solution:
//     def numIslands(self, grid: List[List[str]]) -> int:
//         def dfs(i,j,g,vis):
//             if i>=len(g) or j>=len(g[0]) or i<0 or j<0 or g[i][j]=='0' or vis[i][j]: return 

//             vis[i][j]=1
//             dfs(i+1,j,g,vis)
//             dfs(i-1,j,g,vis)
//             dfs(i,j+1,g,vis)
//             dfs(i,j-1,g,vis)
//         n=len(grid)
//         m=len(grid[0])
//         vis= [[0 for i in range(m)] for j in range(n)]
//         ans=0
//         for i in range(n):
//             for j in range(m): 
//                 if grid[i][j]=='1' and not vis[i][j]: 
//                     dfs(i,j,grid,vis)
//                     ans+=1
//         return ans
    


// In javascript

// /**
//  * @param {character[][]} grid
//  * @return {number}
//  */
// var numIslands = function(grid) {
//     let n=grid.length,m=grid[0].length;
//     let ans=0;
//     for(let i=0;i<n;i++){
//         for(let j=0;j<m;j++){ 
//             if(grid[i][j]=='1'){ 
//                 dfs(i,j,grid);
//                 ans++;
//             }
//         }
//     }
//     return ans;
// };
// var dfs =  (i,j,g)=>{
//     if(i>=g.length || j>=g[0].length || i<0 || j<0 || g[i][j]=='0') return ;
//     g[i][j]='0';
//     dfs(i+1,j,g);
//     dfs(i-1,j,g);
//     dfs(i,j+1,g);
//     dfs(i,j-1,g);
// }
