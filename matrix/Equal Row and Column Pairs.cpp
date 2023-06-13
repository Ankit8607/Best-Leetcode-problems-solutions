// https://leetcode.com/problems/equal-row-and-column-pairs/

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans=0,n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int flag=1;
                for(int k=0;k<n;k++){
                    if(grid[i][k]!= grid[k][j]){
                        flag=0;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};
