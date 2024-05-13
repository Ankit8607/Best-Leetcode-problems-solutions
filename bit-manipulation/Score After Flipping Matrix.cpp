// https://leetcode.com/problems/score-after-flipping-matrix/description/?envType=daily-question&envId=2024-05-13

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int>col(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++) 
                    grid[i][j]=1-grid[i][j];
            }
            for(int j=0;j<m;j++) col[j]+=grid[i][j];
            if(i==n-1){
                for(int j=0;j<m;j++){
                    if(col[j]<=n/2) col[j]=n-col[j];
                    ans+=pow(2,m-j-1)*col[j];
                }
            }
        }
        return ans;
    }
};


// In python

// class Solution:
//     def matrixScore(self, grid: List[List[int]]) -> int:
//         n,m=len(grid),len(grid[0])
//         col = [0 for i in range(m)]
//         ans=0
//         for i in range(n):
//             if grid[i][0]==0:
//                 for j in range(m):
//                     grid[i][j]=1-grid[i][j]
//             for j in range(m): col[j]+=grid[i][j]
//             if i==n-1:
//                 for j in range(m):
//                     if col[j]<=n/2: col[j]=n-col[j]
//                     ans+=pow(2,m-j-1)*col[j]
//         return ans


// In javascript

// /**
//  * @param {number[][]} grid
//  * @return {number}
//  */
// var matrixScore = function(grid) {
//     let n=grid.length,m=grid[0].length;
//     col=new Array(m).fill(0);
//     let ans=0;
//     for(let i=0;i<n;i++){
//         if(grid[i][0]==0){
//             for(let j=0;j<m;j++) 
//                 grid[i][j]=1-grid[i][j];
//         }
//         for(let j=0;j<m;j++) col[j]+=grid[i][j];
//         if(i==n-1){
//             for(let j=0;j<m;j++){
//                 if(col[j]<=n/2) col[j]=n-col[j];
//                 ans+=Math.pow(2,m-j-1)*col[j];
//             }
//         }
//     }
//     return ans;
// };
