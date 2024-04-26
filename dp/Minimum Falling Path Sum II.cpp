// https://leetcode.com/problems/minimum-falling-path-sum-ii/description/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int last=-1;
        int ans1=0,ans2=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){ 
                if(last==j) grid[i][j]+=ans2; 
                else grid[i][j]+=ans1;
            }
            ans1=1e9; ans2=1e9;
            for(int j=0;j<m;j++){
                if(grid[i][j]<ans1) ans2=ans1,ans1=grid[i][j],last=j;
                else if(grid[i][j]<ans2) ans2=grid[i][j];
            }
        }
        return ans1;
    }
};
