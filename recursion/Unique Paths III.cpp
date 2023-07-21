// https://leetcode.com/problems/unique-paths-iii/description/

class Solution {
public:

    int rec(int i, int j, int cnt, vector<vector<int>>&grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==-1) return 0;
        
        if(grid[i][j]==2){
            return cnt==0?1:0;
        }

        grid[i][j]=-1;
        int ans=rec(i+1,j,cnt-1,grid);
        ans+=rec(i-1,j,cnt-1,grid);
        ans+=rec(i,j-1,cnt-1,grid);
        ans+=rec(i,j+1,cnt-1,grid);
        grid[i][j]=0;

        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int,int> st;
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) st={i,j};
                else if(grid[i][j]==0) cnt++;
            }
        }
        return rec(st.first,st.second, cnt+1, grid);
    }
};
