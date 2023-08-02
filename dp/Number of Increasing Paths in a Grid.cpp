// https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/

class Solution {
public:
    int mod=1e9+7;
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back({grid[i][j],{i,j}});
            }
        }
        sort(v.begin(),v.end());

        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int t=v.size()-1;t>=0;t--){
            int val=v[t].first,i=v[t].second.first,j=v[t].second.second;
            dp[i][j]=1;
            if(i+1<n and grid[i+1][j]>grid[i][j]) dp[i][j]+=dp[i+1][j]; 
            dp[i][j]%=mod;
            if(i-1>=0 and grid[i-1][j]>grid[i][j]) dp[i][j]+=dp[i-1][j]; 
            dp[i][j]%=mod;
            if(j-1>=0 and grid[i][j-1]>grid[i][j]) dp[i][j]+=dp[i][j-1]; 
            dp[i][j]%=mod;
            if(j+1<m and grid[i][j+1]>grid[i][j]) dp[i][j]+=dp[i][j+1];
            dp[i][j]%=mod;
            ans+=dp[i][j]; 
            ans%=mod;
        }
        return ans;
    }
};
