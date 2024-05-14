// https://leetcode.com/problems/path-with-maximum-gold/description/?envType=daily-question&envId=2024-05-14

class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int rec(int i,int j,vector<vector<int>>&grid){
        if(i>=grid.size() || i<0 || j>=grid[0].size() || j<0 || grid[i][j]==0) return 0;

        int mx=0,curr=grid[i][j];
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            mx=max(mx,rec(x,y,grid));
        }
        grid[i][j]=curr;
        return mx+curr;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]) ans=max(ans,rec(i,j,grid));
            }
        }
        return ans;
    }
};


// In python

// class Solution:
//     def getMaximumGold(self, grid: List[List[int]]) -> int:
//         n=len(grid)
//         m=len(grid[0])
//         dx=[0,0,1,-1]
//         dy=[1,-1,0,0]
//         def rec(i,j,grid):
//             if i>=n or i<0 or j>=m or j<0 or grid[i][j]==0: return 0
    
//             mx=0
//             curr=grid[i][j]
//             grid[i][j]=0
//             for k in range(4):
//                 x=i+dx[k]
//                 y=j+dy[k]
//                 mx=max(mx,rec(x,y,grid))
//             grid[i][j]=curr
//             return mx+curr
//         ans=0
//         for i in range(n):
//             for j in range(m):
//                 if grid[i][j]: 
//                     ans=max(ans,rec(i,j,grid))
//         return ans


// In javascript

// /**
//  * @param {number[][]} grid
//  * @return {number}
//  */
// var getMaximumGold = function(grid) {
//     let n=grid.length,m=grid[0].length,ans=0;
//     for(let i=0;i<n;i++){
//         for(let j=0;j<m;j++){
//             if(grid[i][j]) ans=Math.max(ans,rec(i,j,grid));
//         }
//     }
//     return ans;
// };

// let dx=[0,0,1,-1];
// let dy=[1,-1,0,0];
// var rec=(i,j,grid)=>{
//     if(i>=grid.length || i<0 || j>=grid[0].length || j<0 || grid[i][j]==0) return 0;
//     let mx=0,curr=grid[i][j];
//     grid[i][j]=0;
//     for(let k=0;k<4;k++){
//         let x=i+dx[k];
//         let y=j+dy[k];
//         mx=Math.max(mx,rec(x,y,grid));
//     }
//     grid[i][j]=curr;
//     return mx+curr;
// };
