// https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/?envType=daily-question&envId=2023-12-14

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>diff(n,vector<int>(m));
        vector<int>row(n,0),col(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i]+=grid[i][j];
                col[j]+=grid[i][j];
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                diff[i][j]=row[i]+col[j]-(n-row[i]+m-col[j]);
        return diff;
    }
};
