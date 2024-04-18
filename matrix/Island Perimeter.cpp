// https://leetcode.com/problems/island-perimeter/description/?envType=daily-question&envId=2024-04-18

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans+=4;
                    if(i>0&&grid[i-1][j]==1) ans-=2;
                    if(j>0&&grid[i][j-1]==1) ans-=2;
                }
            }
        }
        return ans;
    }
};


// In python

// class Solution:
//     def islandPerimeter(self, grid: List[List[int]]) -> int:
//         ans=0
//         for i in range(len(grid)):
//             for j in range(len(grid[0])):
//                 if grid[i][j]:
//                     ans+=4
//                     if i>0 and grid[i-1][j]: ans-=2
//                     if j>0 and grid[i][j-1]: ans-=2
//         return ans


// In javascript

// /**
//  * @param {number[][]} grid
//  * @return {number}
//  */
// var islandPerimeter = function(grid) {
//     let ans=0;
//     for(let i=0;i<grid.length;i++){
//         for(let j=0;j<grid[0].length;j++){
//             if(grid[i][j]==1){
//                 ans+=4;
//                 if(i>0&&grid[i-1][j]==1) ans-=2;
//                 if(j>0&&grid[i][j-1]==1) ans-=2;
//             }
//         }
//     }
//     return ans;
// };
